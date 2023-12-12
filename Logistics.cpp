#include <iostream>
#include <string>
#include "ctime"
#include "Util.h"
#include "Logistics.h"
#include "Hub.h"
#include "Packet.h"
#include "CentralStation.h"

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
        cout<< "Hub "<< hub.getPc().name<< endl;
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
    return Hub();
}


void Logistics::showNextPacket(Hub hub){ //Show in the screen the next packet in the hub given

}

void Logistics::showStatistics(){ //Show statistics

}

Packet Logistics::searchPacket(){ //Ask the user for a label, search the packet and return it

}

void Logistics::removePacket(Hub hub){ //Ask the user for a label and remove the packet

}

void Logistics::transportPacket(Packet packet, Hub hub){ //Move the packet to the pc and delete it from the spcs

}

void Logistics::movePCPacket(Packet packet, Hub hub){ //Move the packet to the new hub and delete it from the old one

}

void Logistics::carryOnDelivery(){ //Ni idea loco

}