#ifndef UNTITLED2_HUB_H
#define UNTITLED2_HUB_H
#include "DynamicStack.h"
#include "Util.h"

using std::cout; using std::cin; using std::endl; using std::string;

class Hub{

private:
    PC pcs;
    DynamicStack hubStack;

public:
    Hub();
    int getPostalCode()const;
    void pushHub(Packet &packet);
    void processPackets();
    Packet searchPacketHub(const string &packetLabel);
    bool movePacketToAnotherHub(AVL& hubsTree, const string &packetLabel);
    void deletePacketInHub(const string &packetLabel);
    void displayPacketsInHub();
    void displayProcessedPacketsInHub();
    PC& getPc();

};


#endif //UNTITLED2_HUB_H
