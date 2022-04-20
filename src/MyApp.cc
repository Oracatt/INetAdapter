#include "MyApp.h"
#include "MyPacket_m.h"
#include "inet/common/ptr.h"
#include "inet/linklayer/common/Ieee802Ctrl.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/INETDefs.h"
#include "inet/linklayer/ieee80211/mac/Rx.h"
#include "inet/linklayer/ieee80211/mac/coordinationfunction/Dcf.h"
#include "inet/linklayer/common/Ieee802SapTag_m.h"
#include "inet/linklayer/common/MacAddressTag_m.h"
#include <stdio.h>

using namespace inet;

Define_Module(MyApp);

#define MSGKIND_SCHEDULE 1
#define PACKETTYPE_PING 1

simsignal_t  MyApp::m_neighbourNum = registerSignal("neighbourNum");

void MyApp::initialize(int stage)
{
    cSimpleModule::initialize(stage);
    if (stage == 0)
    {
        nodeIndex = par("nodeIndex");
        m_llcSocket.setOutputGate(gate("out"));
        m_llcSocket.setCallback(this);
    }
    else if (stage == 2)
    {
        m_llcSocket.open(-1, m_localSap);
        scheduleMsg = new cMessage("App Registration Event");
        scheduleMsg->setKind(MSGKIND_SCHEDULE);
        scheduleAt(simTime()+SimTime(150*nodeIndex,SIMTIME_MS),  scheduleMsg);
    }
}

int MyApp::numInitStages() const
{
    return 3;
}

void MyApp::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage() && msg->getKind() ==  MSGKIND_SCHEDULE)
    {
        sendPingPacket();
        checkNeighbours();
        scheduleAt(simTime()+SimTime(1,SIMTIME_S), msg);
    }
    else
    {
        m_llcSocket.processMessage(msg);
    }
}

void MyApp::finish()
{
    m_llcSocket.close();
    cancelAndDelete(scheduleMsg);
    scheduleMsg=nullptr;
}

void MyApp::socketDataArrived(Ieee8022LlcSocket *socket, Packet *packet)
{
    auto typeMsg = packet->popAtFront<MyPacketType>();
    int type=typeMsg->getType();
    if(type==PACKETTYPE_PING)
    {
        auto dataMsg = packet->popAtFront<MyPingPacket>();
        addNeighbour(dataMsg->getSenderID());
    }
    delete packet;
}

void MyApp::socketClosed(Ieee8022LlcSocket *socket)
{

}

void MyApp::addNeighbour(int nodeID)
{
    if(!hasNeighbour(nodeID))
    {
        neighbours.push_back({nodeID,0});
        emit(m_neighbourNum,(long)neighbours.size());
    }
    else
    {
        for(auto& n:neighbours)
        {
            if(n.neighbourID==nodeID)
                n.delay=0;
        }
    }
}

bool MyApp::hasNeighbour(int nodeID)
{
    for(auto n:neighbours)
    {
        if(n.neighbourID==nodeID)
            return true;
    }
    return false;
}

void MyApp::sendMyPacket()
{
    /*
    //EV_INFO << "send ping packet";
    Packet *dataPacket = new Packet("ping", IEEE802CTRL_DATA);
    Ptr<MyPacket> dataMsg=makeShared<MyPacket>();
    dataMsg->setSenderID(nodeIndex);
    dataMsg->setChunkLength(B(6+4*neighbours.size()));
    dataMsg->setDataArraySize(4*neighbours.size());
    dataMsg->setDataLen(neighbours.size());
    int index=0;
    for(auto n:neighbours)
        dataMsg->setData(index++,n);
    dataPacket->insertAtBack(dataMsg);
    dataPacket->addTag<MacAddressReq>()->setDestAddress(MacAddress::BROADCAST_ADDRESS);
    auto ieee802Sap = dataPacket->addTag<Ieee802SapTagBase>();
    ieee802Sap->setSsap(m_localSap);
    ieee802Sap->setDsap(m_remoteSap);
    m_llcSocket.send(dataPacket);
    */
}

void MyApp::sendPingPacket()
{
    Packet *dataPacket = new Packet("ping", IEEE802CTRL_DATA);
    Ptr<MyPacketType> typeMsg=makeShared<MyPacketType>();
    typeMsg->setChunkLength(B(2));
    typeMsg->setType(PACKETTYPE_PING);
    dataPacket->insertAtBack(typeMsg);
    Ptr<MyPingPacket> dataMsg=makeShared<MyPingPacket>();
    dataMsg->setSenderID(nodeIndex);
    dataMsg->setChunkLength(B(4));
    dataPacket->insertAtBack(dataMsg);
    dataPacket->addTag<MacAddressReq>()->setDestAddress(MacAddress::BROADCAST_ADDRESS);
    auto ieee802Sap = dataPacket->addTag<Ieee802SapTagBase>();
    ieee802Sap->setSsap(m_localSap);
    ieee802Sap->setDsap(m_remoteSap);
    m_llcSocket.send(dataPacket);
}

void MyApp::checkNeighbours()
{
    for(auto& n:neighbours)
    {
        n.delay++;
    }
    neighbours.remove_if([=](const MyNeighbourNodeInfo& info)->bool{return info.delay==4;});
    EV_INFO<<"node:"<<nodeIndex;
    for(auto n:neighbours)
    {
        EV_INFO<<"neighbour:"<<n.neighbourID<<" delay:"<<n.delay;
    }
}
