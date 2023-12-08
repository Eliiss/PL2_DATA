#include <iostream>
#include <string>

#include "Logistics.h"
#include "Hub.h"
#include "Packet.h"
#include "AVL.h"
#include "Hub.h"
#include "CentralStation.h"

using std::cout; using std::cin; using std::endl; using std::string;

void Logistics::initialise(){

    //creation of hubs and insertion in AVL
    for (int i =0; i<N2; i++){
        Hub hub;
        hubInTree.insert(hub.getPostalCode(i),hub); //postal code is the key for the tree and the hub is the element
    }
}

Hub Logistics::getSelectedPC(){ //Ask the user for a PC and return it

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