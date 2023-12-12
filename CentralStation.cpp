#include <iostream>
#include <string>
#include <ctime>

#include "CentralStation.h"
#include "Packet.h"

using std::cout; using std::cin; using std::endl; using std::string;

CentralStation::CentralStation() : packetsProcessed(0), generatedPackets (0){

}

void CentralStation::insertPacket(Packet &packet) {
    packetInList.insertBeginning(packet);

}

void CentralStation::insertMiddle(Nodo *prev_node, Packet &packet) {
    packetInList.insertMiddle(prev_node, packet);
}

void CentralStation::insertEnd(Packet &packet) {
    packetInList.insertEnd(packet);
}

void CentralStation::transferPackets(Packet packet){
    packetInList.transportPacket(packet);
    packetsProcessed++;
}

void CentralStation::processToHub() {
    packetInList.process(N3);
}


Packet CentralStation::searchByID(const string &packetLabel) {
    return packetInList.searchByID(packetLabel);
}

void CentralStation:: displayPackets (){
    packetInList.displayPacketsForHub();
}

int CentralStation:: getPacketsProcessed() const{
    return packetsProcessed;
}


void CentralStation::generatePackets(int numberToGenerate, int seed){

    srand(seed);

    Packet packet;
    generatedPackets++;
    packet.setPacketNumber(generatedPackets);
    packet.assignLatitude();
    packet.assignLongitude();
    packet.assignLabel();
    packet.assignUrgent();
    packet.assignDni();
    packet.setStatus(PROCESSING);
    packetInList.insertEnd(packet); //FIFO First In First Out



    int statusi = packet.getStatus();
    string status;
    switch(statusi){
        case 0:
            status = "PROCESSING";
            break;
        case 1:
            status = "DELIVERING";
            break;
        case 2:
            status = "DELIVERED";
            break;
    }

    cout << "Generating new packet... Attributes: " << endl;
    cout << "     Packet ID: " << packet.getLabel() << " for delivery to zone: " << packet.getZone() << endl;
    cout << "     Latitude: " << packet.getLatitude() << " Longitude: " << packet.getLongitude() << endl;
    cout << "     Urgent [0:no 1:yes]:" << packet.getUrgent() << ", Client DNI: " << packet.getDni() << ", Status: " << status << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;


    if (generatedPackets < numberToGenerate){
        seed=seed*(rand() % 35000); //Generamos semillas aleatorias
        generatePackets(numberToGenerate, seed);
    }
}

void CentralStation::resetGeneratedPackets(){
    generatedPackets = 0;
}

int CentralStation::getGeneratedPackets(){
    return totalGeneratedPackets;
}

void CentralStation::addTotalGeneratedPackets(int num){
    totalGeneratedPackets += num;
}

void CentralStation::substractGeneratedPackets(int num){
    totalGeneratedPackets -= num;
}