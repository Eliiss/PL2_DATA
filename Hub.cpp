#include "Hub.h"
#include "AVL.h"
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

Hub::Hub() {}

int Hub::getPostalCode() const {
    return (pcs.postalCode);
}

void Hub::pushHub(Packet &packet){
    hubStack.push(packet);
    cout << "Packet pushed to Hub " << pcs.name << endl;
}

void Hub:: processPackets(){

    hubStack.process();
    cout << N2 << "Packets processed in Hub " << pcs.name<< endl;
}
Packet Hub:: searchPacketHub(const string &packetLabel){
    hubStack.searchPacket(packetLabel);
    cout << "Packet "<<packetLabel << " was found" << endl;
}

bool Hub:: movePacketToAnotherHub(AVL& hubsTree, const string &packetLabel) {
    if (!hubStack.isEmpty()) {
        hubStack.movePacket(hubsTree, packetLabel);
    } else {
        cout << "Source hub is empty. No packet to move." << endl;
    }
}

void Hub::deletePacketInHub(const string &packetLabel) {
     hubStack.deletePacket(packetLabel);
}


void Hub::displayPacketsInHub() {
    cout << "Packets in Hub " << pcs.name << ":" << endl;
    hubStack.displayPackets();
}


void Hub::displayProcessedPacketsInHub() {
    cout << "Processed Packets in Hub " << pcs.name << ":" << endl;
    hubStack.displayProcessedPackets();
}

PC& Hub:: getPc(){
    return pcs;
}