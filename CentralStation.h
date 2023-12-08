#ifndef UNTITLED2_CENTRALSTATION_H
#define UNTITLED2_CENTRALSTATION_H


#include <iostream>
#include <string>
#include "DoubleLinkedList.h"
#include "Hub.h"

using std::cout; using std::cin; using std::endl; using std::string;

class Packet;

class CentralStation{

private:

    DoubleLinkedList packetInList;
    int generatedPackets = 0;
    int packetsProcessed = 0;
    int totalGeneratedPackets = 0;

public:
    CentralStation();
    void generatePackets(int numberToGenerate, int seed);
    void resetGeneratedPackets();
    void insertPacket(Packet &packet);
    void insertMiddle(Nodo *prev_node, Packet &packet);
    void insertEnd(Packet &packet);
    Packet searchByID(const string &packetLabel);
    void displayPackets();
    int getPacketsProcessed() const;
    void transferPackets(Packet packet);
    int getGeneratedPackets();
    void addTotalGeneratedPackets(int num);
    void substractGeneratedPackets(int num);

};
#endif //UNTITLED2_CENTRALSTATION_H
