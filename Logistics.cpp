#include <iostream>
#include <string>
#include "ctime"
#include "Util.h"
#include "Logistics.h"
#include "Hub.h"
#include "Packet.h"

using std::cout; using std::cin; using std::endl; using std::string;

void Logistics::initialise(){

    cout << "Welcome to Salamanca Parcel Delivery App" << endl;

    //creation of hubs and insertion in AVL
    for (int i =0; i<N2; i++){
        hub.getPc().postalCode = postalCodes[i];
        hub.getPc().abbreviation = townAbbreviations[i];
        hub.getPc().name = townNames[i];
        hub.getPc().coordinates = townCoordinates[i];
        hubInTree.insert(hub.getPostalCode(),hub); //postal code is the key for the tree and the hub is the element
        cout<< "Hub "<< hub.getPc().name<< " with postal code: "<< hub.getPc().postalCode<< endl;
    }

    //generation an insertion of the packets

    int seed = time(NULL);
    centralStation.generatePackets(N1, seed);
    centralStation.addTotalGeneratedPackets(N1);

    //assign and process to corresponding Hub
    centralStation.processToHub();

}

Hub Logistics::getSelectedPC() {
    int postalCode;
    cout << "Which Hub would you like to select. Please write the postal code: " << endl;
    cin >> postalCode;

    Hub * foundHub = hubInTree.search(postalCode);
    if (foundHub!= nullptr){
        cout << "Hub found: " << foundHub->getPc().name << " (" << foundHub->getPc().abbreviation << ")" << endl;
        return *foundHub;
    }
    cout << "Hub with postal code " << postalCode << " not found." << endl;
    return Hub();
}


void Logistics::showNextPacket(){ //Show in the screen the next packet in the hub given
    hub = getSelectedPC();
    centralStation.displayNextPacketHub(hub);
}

void Logistics::showStatistics(){ //Show statistics

}

Packet Logistics::searchPacket(){ //Ask the user for a label, search the packet and return it
    string packetLabel;
    cout << "Enter the label of the packet you want to search: ";
    cin >> packetLabel;

    // Search for the packet in central station
    Packet foundPacket = centralStation.searchByID(packetLabel);

    //Search in Hubs if it's not in the central Station

}

void Logistics::removePacket(Hub hub){ //Ask the user for a label and remove the packet
    hub = getSelectedPC();
    string packetLabel;
    cout << "Enter the label of the packet you want to delete: "<< endl;
    cin >> packetLabel;
    hub.deletePacketInHub(packetLabel);
    cout << "Packet with label "<< packetLabel<< " was deleted successfully"<< endl;

}

void Logistics::transportPacket(Packet packet){ //Move the packet to the pc and delete it from the spcs
    centralStation.transferPackets(packet);

}

void Logistics::movePCPacket(){ //Move the packet to the new hub and delete it from the old one
    string packetLabel;
    cout << "Enter the label of the packet you want to delete: "<< endl;
    cin >> packetLabel;

    hub = getSelectedPC();
    hub.movePacketToAnotherHub(hub,packetLabel);
}

void Logistics::carryOnDelivery(){ //Ni idea loco

}