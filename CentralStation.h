#ifndef CentralStation_h
#define CentralStation_h

#include <iostream>
#include <string>
#include "Queue.h"
#include "Hub.h"

using std::cout; using std::cin; using std::endl; using std::string;

class Packet;

class CentralStation{

private:

    Queue packetInQueue;
    Hub hubs[4];
    int generatedPackets = 0;
    int packetsProcessed = 0;
    int totalGeneratedPackets = 0;

public:
    CentralStation();
    void generatePackets(int numberToGenerate, int seed);
    void resetGeneratedPackets();
    void enqueuePacket(Packet &packet);
    void dequeuePacket(int num);
    void displayPackets();
    int getPacketsProcessed() const;
    bool isQueueEmpty();
    void transferPackets(Packet packet);
    Hub * getHub(int index);
    int getGeneratedPackets();
    void addTotalGeneratedPackets(int num);
    void substractGeneratedPackets(int num);

};

#endif