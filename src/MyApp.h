#ifndef MYAPP_H_
#define MYAPP_H_

#include <omnetpp.h>
#include <cstdlib>
#include <ctime>
#include <list>
#include <string>
#include <vector>
#include "inet/linklayer/ieee8022/Ieee8022LlcSocket.h"
#include "MyNeighbourNodeInfo.h"

using namespace inet;

#if OMNETPP_VERSION >= 0x500
using namespace omnetpp;
#endif

using namespace std;

class MyApp : public cSimpleModule,public Ieee8022LlcSocket::ICallback
{
    public:

        virtual void initialize(int stage);

        virtual void handleMessage(cMessage *msg);

        virtual int numInitStages() const;

        virtual void finish();

        virtual void socketDataArrived(Ieee8022LlcSocket *socket, Packet *packet);

        virtual void socketClosed(Ieee8022LlcSocket *socket);

    private:

        int nodeIndex;

        cMessage* scheduleMsg;

        Ieee8022LlcSocket m_llcSocket;

        int m_localSap = -1;

        int m_remoteSap = -1;

        list<MyNeighbourNodeInfo> neighbours;

        static simsignal_t  m_neighbourNum;

        void addNeighbour(int nodeID);

        bool hasNeighbour(int nodeID);

        void sendMyPacket();

        void sendPingPacket();

        void checkNeighbours();
};


#endif
