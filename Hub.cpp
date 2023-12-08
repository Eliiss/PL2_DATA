#include "Hub.h"
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

Hub::Hub() {
    for (int i = 0; i < N2; ++i) {
        pcs[i].postalCode = postalCodes[i];
        pcs[i].abbreviation = townAbbreviations[i];
        pcs[i].name = townNames[i];
        pcs[i].coordinates = townCoordinates[i];
    }
}

int Hub::getPostalCode(int index) const {
    if (index>0 && index>N2){
        return (pcs[index].postalCode);
    }
}

DynamicStack & Hub::getStackByPostalCode(int postalCode) {
    for (int i = 0; i < N2 ; i++){
        if (pcs[i].postalCode == postalCode){
            return hubStack[i];
        }
    }
}

void Hub::pushHub(Packet &packet){
    int hubIndex;
    cout << "Enter the index of the hub to push the packet: ";
    cin >> hubIndex;

    if (hubIndex >= 0 && hubIndex < N2) {
        hubStack[hubIndex].push(packet);
        cout << "Packet pushed to Hub " << hubIndex << endl;
    } else {
        cout << "Invalid hub index." << endl;
    }
}

void Hub:: processPackets(){

    int hubIndex;
    cout << "Enter the index of the hub for processing the packets: ";
    cin >> hubIndex;

    if (hubIndex >= 0 && hubIndex < N2) {
        hubStack[hubIndex].process();
        cout << N2 << "Packets processed " << endl;
    } else {
        cout << "Invalid hub index." << endl;
    }
}
Packet Hub:: searchPacketHub(const string &packetLabel){
    int hubIndex;
    cout << "Enter the index of the hub you want to search the packets from: ";
    cin >> hubIndex;

    if (hubIndex >= 0 && hubIndex < N2) {
        hubStack[hubIndex].searchPacket(packetLabel);
        cout << "Packet"<<packetLabel << "was found" << endl;
    } else {
        cout << "Invalid hub index." << endl;
    }
}

bool Hub:: movePacketToAnotherHub(DynamicStack hubs[], const string &packetLabel){
     int sourceHubIndex;
     cout << "Enter the index of the source hub: ";
     cin >> sourceHubIndex;
        if (sourceHubIndex >= 0 && sourceHubIndex < N2) {
            if (!hubStack[sourceHubIndex].isEmpty()) {
                hubStack[sourceHubIndex].movePacket(hubs, packetLabel);
            } else {
                cout << "Source hub is empty. No packet to move." << endl;
            }
        } else {
            cout << "Invalid source hub index." << endl;
        }
}

void Hub::deletePacketInHub(const string &packetLabel) {
    cout << "Enter the index of the Hub: ";
    int hubIndex;
    cin >> hubIndex;

    if (hubIndex >= 0 && hubIndex < N2) {
        hubStack[hubIndex].deletePacket(packetLabel);
    } else {
        cout << "Invalid index." << endl;
    }
}

void Hub::displayPacketsInHub() {
    cout << "Enter the index of the Hub: ";
    int hubIndex;
    cin >> hubIndex;
    if (hubIndex >= 0 && hubIndex < N2) {
        cout << "Packets in Hub " << pcs[hubIndex].abbreviation << ":" << endl;
        hubStack[hubIndex].displayPackets();
    } else {
        cout << "Invalid  index." << endl;
    }
}

void Hub::displayProcessedPacketsInHub() {
    cout << "Enter the index of the PC: ";
    int hubIndex;
    cin >> hubIndex;

    if (hubIndex >= 0 && hubIndex < N2) {
        cout << "Processed Packets in Hub " << pcs[hubIndex].abbreviation << ":" << endl;
        hubStack[hubIndex].displayProcessedPackets();
    } else {
        cout << "Invalid index." << endl;
    }
}