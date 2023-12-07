#ifndef UNTITLED2_HUB_H
#define UNTITLED2_HUB_H
#include "DynamicStack.h"
#include "Util.h"

using std::cout; using std::cin; using std::endl; using std::string;

class Hub{

private:
    PC pcs[N2];
    DynamicStack hubStack[N2];

public:
    Hub();
    void pushHub(Packet &packet);
    void processPackets();
    Packet searchPacketHub(const string &packetLabel);
    bool movePacketToAnotherHub(DynamicStack hubs[], const string &packetLabel);
    void deletePacketInHub(const string &packetLabel);
    void displayPacketsInHub();
    void displayProcessedPacketsInHub();

};


#endif //UNTITLED2_HUB_H
