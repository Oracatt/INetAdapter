#ifndef INETADAPTER_H_
#define INETADAPTER_H_

#include "inet/mobility/contract/IMobility.h"
#include "inet/linklayer/ieee8022/Ieee8022LlcSocket.h"

#include <omnetpp.h>
#include <cstdlib>
#include <string>
#include <queue>
#include "INANeighborInfo.h"

#if OMNETPP_VERSION >= 0x500
using namespace omnetpp;
#endif

using namespace inet;

#define INA_MSGKIND_SCHEDULE 1
#define INA_MSGKIND_PING 2
#define INA_MSGKIND_USER 3

using namespace std;

class INetAdapter: public cSimpleModule,public Ieee8022LlcSocket::ICallback
{
    protected:
        virtual void initialize(int stage);
        virtual void handleMessage(cMessage *msg);
        virtual int numInitStages() const;
        virtual void finish();
        virtual void socketDataArrived(Ieee8022LlcSocket *socket, Packet *packet);
        virtual void socketClosed(Ieee8022LlcSocket *socket);

    private:
        int nodeIndex;
        string ownMACAddress;
        int pingInterval;
        int pingIntervalFloat;

        cMessage* scheduleMsg;

        int m_localSap = -1;
        int m_remoteSap = -1;
        Ieee8022LlcSocket m_llcSocket;

        list<INANeighborInfo> neighborList;

        void checkNeighbors();
        void sendUpdatePacket();
        void sendUserPacket(cMessage* msg);
        INANeighborInfo* findNeighbor(int id);
        INANeighborInfo* findNeighbor(const string& mac);
        void updateDelay(int id);
        void addNewNeighbor(int id,const string& mac);
        string getDestinationAddress(cMessage *msg);
};

#endif /* INETADAPTER_H_ */
