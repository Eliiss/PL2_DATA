#include <iostream>
#include <string>
#include <ctime>

#include "CentralStation.h"
#include "Packet.h"

using std::cout; using std::cin; using std::endl; using std::string;

CentralStation::CentralStation() : packetsProcessed(0), generatedPackets (0){

}

void CentralStation::enqueuePacket (Packet &packet){
    packetInQueue.enqueue(packet);
}

void CentralStation::transferPackets(Packet packet){

    string deliveryZone = packet.getZone();

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
    
    cout << "Processing packet ID: " << packet.getLabel() << " for delivery to zone: " << deliveryZone << endl;
    cout << "Latitude: " << packet.getLatitude() << " Longitude: " << packet.getLongitude() << endl;
    cout << "Urgent [0:no 1:yes]:" << packet.getUrgent() << ", Client DNI: " << packet.getDni() << ", Status: " << status << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    if (deliveryZone == "NE") {
        hubs[0].pushPacket(packet);
    } else if (deliveryZone == "NW") {
        hubs[1].pushPacket(packet);
    } else if (deliveryZone == "SE") {
        hubs[2].pushPacket(packet);
    } else if (deliveryZone == "SW") {
        hubs[3].pushPacket(packet);
    }
    packetsProcessed++;
}

void CentralStation::dequeuePacket(int num) {
    for(int i=0; i<num; i++){
        Packet packet = packetInQueue.dequeue();
        packet.setStatus(DELIVERING);
        transferPackets(packet);
    }
}

Hub* CentralStation::getHub(int index) {
    if (index >= 0 && index < 4) {
        return &hubs[index];
    }
    return nullptr;
}

void CentralStation:: displayPackets (){
    packetInQueue.display();
}

int CentralStation:: getPacketsProcessed() const{
    return packetsProcessed;
}

bool CentralStation::isQueueEmpty() {
    return packetInQueue.isEmpty();
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
    packetInQueue.enqueue(packet);
    
    
    
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
