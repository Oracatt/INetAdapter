#include "INetAdapter.h"
#include "inet/common/ptr.h"
#include "inet/linklayer/common/Ieee802Ctrl.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/INETDefs.h"
#include "inet/linklayer/ieee80211/mac/Rx.h"
#include "inet/linklayer/ieee80211/mac/coordinationfunction/Dcf.h"
#include "inet/linklayer/common/Ieee802SapTag_m.h"
#include "inet/linklayer/common/MacAddressTag_m.h"
#include "INAMessage_m.h"
#include "KOPSMsg_m.h"
#include "KInternalMsg_m.h"
#include <random>

using namespace inet;

Define_Module(INetAdapter);

default_random_engine randomEngine;
#define RAND(a,b) uniform_int_distribution<unsigned >(a,b)(randomEngine)

void INetAdapter::initialize(int stage)
{
    if (stage == 0) {

        ownMACAddress = par("ownMACAddress").stringValue();
        pingInterval = par("pingInterval");
        pingIntervalFloat = par("pingIntervalFloat");
        nodeIndex = par("nodeIndex");

        m_llcSocket.setOutputGate(gate("lowerLayerOut"));
        m_llcSocket.setCallback(this);

    } else if (stage == 2) {

        m_llcSocket.open(-1, m_localSap);
        scheduleMsg = new cMessage("Update Neighbor Event");
        scheduleMsg->setKind(INA_MSGKIND_SCHEDULE);
        scheduleAt(simTime()+SimTime(pingInterval+RAND(-pingIntervalFloat,pingIntervalFloat),SIMTIME_MS), scheduleMsg);
    }
}

int INetAdapter::numInitStages() const
{
    return 3;
}

void INetAdapter::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage() && msg->getKind() == INA_MSGKIND_SCHEDULE) {
        checkNeighbors();
        sendUpdatePacket();
        scheduleAt(simTime()+SimTime(pingInterval+RAND(-pingIntervalFloat,pingIntervalFloat),SIMTIME_MS), scheduleMsg);
    }
    else {
        cGate *gate;
        char gateName[32];
        gate = msg->getArrivalGate();
        strcpy(gateName, gate->getName());

        if (strstr(gateName, "upperLayerIn") != NULL) {
            sendUserPacket(msg);
        }
        else {
            m_llcSocket.processMessage(msg);
        }
    }
}


void INetAdapter::socketDataArrived(Ieee8022LlcSocket *socket, Packet *packet)
{
    const auto typeMsg = packet->popAtFront<INATypeMsg>();
    int type=typeMsg->getMsgKind();
    int senderID=typeMsg->getSenderID();
    updateDelay(senderID);
    if(type==INA_MSGKIND_PING)
    {
        const auto dataMsg = packet->popAtFront<INAUpdateMsg>();
        int nCount=dataMsg->getNeighborCount();
        bool found=false;
        for(int i=0;i<nCount;i++)
        {
            if(dataMsg->getNeighborID(i)==nodeIndex)
            {
                found=true;
                break;
            }
        }
        if(found)
        {
            auto senderInfo=findNeighbor(senderID);
            if(senderInfo)
            {
                senderInfo->ack=true;
            }
            else
            {
                addNewNeighbor(senderID,dataMsg->getMacAddress());
            }
        }
        else if(!findNeighbor(senderID))
        {
            addNewNeighbor(senderID,dataMsg->getMacAddress());
        }
    }
    else if(INA_MSGKIND_USER)
    {
        const auto headerMsg = packet->popAtFront<INAUserMsgHeader>();
        switch(headerMsg->getPtrType())
        {
        case 0:
        {
            auto dataMsg=packet->popAtFront<INAUserMsg_KDataMsg>();
            KDataMsg* data=new KDataMsg(dataMsg->getData());
            string dst=data->getDestinationAddress();
            if(dst==ownMACAddress||dst=="FF:FF:FF:FF:FF:FF")
                send(data, "upperLayerOut");
            break;
        }
        case 1:
        {
            auto dataMsg=packet->popAtFront<INAUserMsg_KFeedbackMsg>();
            KFeedbackMsg* data=new KFeedbackMsg(dataMsg->getData());
            string dst=data->getDestinationAddress();
            if(dst==ownMACAddress||dst=="FF:FF:FF:FF:FF:FF")
                send(data, "upperLayerOut");
            break;
        }
        case 2:
        {
            auto dataMsg=packet->popAtFront<INAUserMsg_KSummaryVectorMsg>();
            KSummaryVectorMsg* data=new KSummaryVectorMsg(dataMsg->getData());
            string dst=data->getDestinationAddress();
            if(dst==ownMACAddress||dst=="FF:FF:FF:FF:FF:FF")
                send(data, "upperLayerOut");
            break;
        }
        case 3:
        {
            auto dataMsg=packet->popAtFront<INAUserMsg_KDataRequestMsg>();
            KDataRequestMsg* data=new KDataRequestMsg(dataMsg->getData());
            string dst=data->getDestinationAddress();
            if(dst==ownMACAddress||dst=="FF:FF:FF:FF:FF:FF")
                send(data, "upperLayerOut");
            break;
        }
        case 4:
        {
            auto dataMsg=packet->popAtFront<INAUserMsg_KReactionMsg>();
            KReactionMsg* data=new KReactionMsg(dataMsg->getData());
            string dst=data->getDestinationAddress();
            if(dst==ownMACAddress||dst=="FF:FF:FF:FF:FF:FF")
                send(data, "upperLayerOut");
            break;
        }
        case 5:
        {
            auto dataMsg=packet->popAtFront<INAUserMsg_KDPtableRequestMsg>();
            KDPtableRequestMsg* data=new KDPtableRequestMsg(dataMsg->getData());
            string dst=data->getDestinationAddress();
            if(dst==ownMACAddress||dst=="FF:FF:FF:FF:FF:FF")
                send(data, "upperLayerOut");
            break;
        }
        case 6:
        {
            auto dataMsg=packet->popAtFront<INAUserMsg_KDPtableDataMsg>();
            KDPtableDataMsg* data=new KDPtableDataMsg(dataMsg->getData());
            string dst=data->getDestinationAddress();
            if(dst==ownMACAddress||dst=="FF:FF:FF:FF:FF:FF")
                send(data, "upperLayerOut");
            break;
        }
        }
    }
    delete packet;
}

void INetAdapter::socketClosed(Ieee8022LlcSocket *socket)
{

}

void INetAdapter::finish()
{
    if (scheduleMsg->isScheduled()) {
        cancelEvent(scheduleMsg);
    }
    delete scheduleMsg;
    m_llcSocket.close();
}

void INetAdapter::sendUpdatePacket()
{
    Packet *dataPacket = new Packet("ping", IEEE802CTRL_DATA);
    Ptr<INATypeMsg> typeMsg=makeShared<INATypeMsg>();
    typeMsg->setChunkLength(B(8));
    typeMsg->setMsgKind(INA_MSGKIND_PING);
    typeMsg->setSenderID(nodeIndex);
    dataPacket->insertAtBack(typeMsg);
    Ptr<INAUpdateMsg> dataMsg=makeShared<INAUpdateMsg>();
    dataMsg->setChunkLength(B(2+5*neighborList.size()+sizeof(string)));
    dataMsg->setNeighborCount(neighborList.size());
    dataMsg->setNeighborIDArraySize(neighborList.size());
    dataMsg->setAckArraySize(neighborList.size());
    dataMsg->setMacAddress(ownMACAddress.c_str());
    int index=0;
    for(auto it=neighborList.begin();it!=neighborList.end();it++)
    {
        dataMsg->setAck(index, it->ack);
        dataMsg->setNeighborID(index,it->neighborID);
        index++;
    }
    dataPacket->insertAtBack(dataMsg);
    dataPacket->addTag<MacAddressReq>()->setDestAddress(MacAddress::BROADCAST_ADDRESS);
    auto ieee802Sap = dataPacket->addTag<Ieee802SapTagBase>();
    ieee802Sap->setSsap(m_localSap);
    ieee802Sap->setDsap(m_remoteSap);
    m_llcSocket.send(dataPacket);
}

void INetAdapter::sendUserPacket(cMessage* msg)
{
    string dst=getDestinationAddress(msg);
    if(dst=="FF:FF:FF:FF:FF:FF"||findNeighbor(dst))
    {
        Packet *dataPacket = new Packet("ping", IEEE802CTRL_DATA);
        Ptr<INATypeMsg> typeMsg=makeShared<INATypeMsg>();
        typeMsg->setChunkLength(B(8));
        typeMsg->setMsgKind(INA_MSGKIND_USER);
        typeMsg->setSenderID(nodeIndex);
        dataPacket->insertAtBack(typeMsg);
        if(dynamic_cast<KDataMsg*>(msg))
        {
            Ptr<INAUserMsgHeader> headerMsg=makeShared<INAUserMsgHeader>();
            headerMsg->setChunkLength(B(4));
            headerMsg->setPtrType(0);
            dataPacket->insertAtBack(headerMsg);
            Ptr<INAUserMsg_KDataMsg> dataMsg=makeShared<INAUserMsg_KDataMsg>();
            dataMsg->setChunkLength(B(sizeof(KDataMsg)));
            dataMsg->setData(*((KDataMsg*)msg));
            dataPacket->insertAtBack(dataMsg);
        }
        else if(dynamic_cast<KFeedbackMsg*>(msg))
        {
            Ptr<INAUserMsgHeader> headerMsg=makeShared<INAUserMsgHeader>();
            headerMsg->setChunkLength(B(4));
            headerMsg->setPtrType(1);
            dataPacket->insertAtBack(headerMsg);
            Ptr<INAUserMsg_KFeedbackMsg> dataMsg=makeShared<INAUserMsg_KFeedbackMsg>();
            dataMsg->setChunkLength(B(sizeof(KFeedbackMsg)));
            dataMsg->setData(*((KFeedbackMsg*)msg));
            dataPacket->insertAtBack(dataMsg);
        }
        else if(dynamic_cast<KSummaryVectorMsg*>(msg))
        {
            Ptr<INAUserMsgHeader> headerMsg=makeShared<INAUserMsgHeader>();
            headerMsg->setChunkLength(B(4));
            headerMsg->setPtrType(2);
            dataPacket->insertAtBack(headerMsg);
            Ptr<INAUserMsg_KSummaryVectorMsg> dataMsg=makeShared<INAUserMsg_KSummaryVectorMsg>();
            dataMsg->setChunkLength(B(sizeof(KSummaryVectorMsg)));
            dataMsg->setData(*((KSummaryVectorMsg*)msg));
            dataPacket->insertAtBack(dataMsg);
        }
        else if(dynamic_cast<KDataRequestMsg*>(msg))
        {
            Ptr<INAUserMsgHeader> headerMsg=makeShared<INAUserMsgHeader>();
            headerMsg->setChunkLength(B(4));
            headerMsg->setPtrType(3);
            dataPacket->insertAtBack(headerMsg);
            Ptr<INAUserMsg_KDataRequestMsg> dataMsg=makeShared<INAUserMsg_KDataRequestMsg>();
            dataMsg->setChunkLength(B(sizeof(KDataRequestMsg)));
            dataMsg->setData(*((KDataRequestMsg*)msg));
            dataPacket->insertAtBack(dataMsg);
        }
        else if(dynamic_cast<KReactionMsg*>(msg))
        {
            Ptr<INAUserMsgHeader> headerMsg=makeShared<INAUserMsgHeader>();
            headerMsg->setChunkLength(B(4));
            headerMsg->setPtrType(4);
            dataPacket->insertAtBack(headerMsg);
            Ptr<INAUserMsg_KReactionMsg> dataMsg=makeShared<INAUserMsg_KReactionMsg>();
            dataMsg->setChunkLength(B(sizeof(KReactionMsg)));
            dataMsg->setData(*((KReactionMsg*)msg));
            dataPacket->insertAtBack(dataMsg);
        }
        else if(dynamic_cast<KDPtableRequestMsg*>(msg))
        {
            Ptr<INAUserMsgHeader> headerMsg=makeShared<INAUserMsgHeader>();
            headerMsg->setChunkLength(B(4));
            headerMsg->setPtrType(5);
            dataPacket->insertAtBack(headerMsg);
            Ptr<INAUserMsg_KDPtableRequestMsg> dataMsg=makeShared<INAUserMsg_KDPtableRequestMsg>();
            dataMsg->setChunkLength(B(sizeof(KDPtableRequestMsg)));
            dataMsg->setData(*((KDPtableRequestMsg*)msg));
            dataPacket->insertAtBack(dataMsg);
        }
        else if(dynamic_cast<KDPtableDataMsg*>(msg))
        {
            Ptr<INAUserMsgHeader> headerMsg=makeShared<INAUserMsgHeader>();
            headerMsg->setChunkLength(B(4));
            headerMsg->setPtrType(6);
            dataPacket->insertAtBack(headerMsg);
            Ptr<INAUserMsg_KDPtableDataMsg> dataMsg=makeShared<INAUserMsg_KDPtableDataMsg>();
            dataMsg->setChunkLength(B(sizeof(KDPtableDataMsg)));
            dataMsg->setData(*((KDPtableDataMsg*)msg));
            dataPacket->insertAtBack(dataMsg);
        }
        dataPacket->addTag<MacAddressReq>()->setDestAddress(MacAddress::BROADCAST_ADDRESS);
        auto ieee802Sap = dataPacket->addTag<Ieee802SapTagBase>();
        ieee802Sap->setSsap(m_localSap);
        ieee802Sap->setDsap(m_remoteSap);
        m_llcSocket.send(dataPacket);
    }
    delete msg;
}

void INetAdapter::checkNeighbors()
{
    for(auto& p:neighborList)
        p.delay++;
    neighborList.remove_if([=](const INANeighborInfo& info)->bool{return info.delay>=5;});
}

INANeighborInfo* INetAdapter::findNeighbor(int id)
{
    for(auto& p:neighborList)
        if(p.neighborID==id)
            return &p;
    return 0;
}

INANeighborInfo* INetAdapter::findNeighbor(const string& mac)
{
    for(auto& p:neighborList)
        if(p.macAddress==mac)
            return &p;
    return 0;
}

void INetAdapter::updateDelay(int id)
{
    for(auto& p:neighborList)
        if(p.neighborID==id)
            p.delay=0;
}

void INetAdapter::addNewNeighbor(int id,const string& mac)
{
    INANeighborInfo info;
    info.neighborID=id;
    info.ack=false;
    info.delay=0;
    info.macAddress=mac;
    neighborList.push_back(info);
}

string INetAdapter::getDestinationAddress(cMessage *msg)
{
    KDataMsg *dataMsg = dynamic_cast<KDataMsg*>(msg);
    if (dataMsg) {
        return dataMsg->getDestinationAddress();
    }

    KFeedbackMsg *feedbackMsg = dynamic_cast<KFeedbackMsg*>(msg);
    if (feedbackMsg) {
        return feedbackMsg->getDestinationAddress();
    }

    KSummaryVectorMsg *summaryVectorMsg = dynamic_cast<KSummaryVectorMsg*>(msg);
    if (summaryVectorMsg) {
        return summaryVectorMsg->getDestinationAddress();
    }

    KDataRequestMsg *dataRequestMsg = dynamic_cast<KDataRequestMsg*>(msg);
    if (dataRequestMsg) {
        return dataRequestMsg->getDestinationAddress();
    }

    KDPtableRequestMsg *dpTableRequestMsg = dynamic_cast<KDPtableRequestMsg*>(msg);
    if (dpTableRequestMsg) {
        return dpTableRequestMsg->getDestinationAddress();
    }

    KDPtableDataMsg *dpTableDataMsg = dynamic_cast<KDPtableDataMsg*>(msg);
    if (dpTableDataMsg) {
        return dpTableDataMsg->getDestinationAddress();
    }

    throw cRuntimeError("Unknown message type in INetAdapter");

    return string();
}
