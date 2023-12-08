#ifndef UNTITLED2_DYNAMICSTACK_H
#define UNTITLED2_DYNAMICSTACK_H

#include <iostream>
#include "Packet.h"
#include "DoubleLinkedList.h"
#include "Queue.h"

using std::cout; using std::cin; using std::endl; using std::string;

struct Node; //reusing queue node

class DynamicStack{

private:
    Node* top;
    Queue packetsProcessedHub;


public:
    DynamicStack();
    ~DynamicStack();

    bool isEmpty();
    int getSize() const;
    void push(Packet &packet);
    Packet pop ();
    void process();
    Packet searchPacket(const string &packetLabel);
    bool movePacket(DynamicStack hubs[], const string &packetLabel);
    void deletePacket(const string &packetLabel);
    void displayPackets();
    void displayProcessedPackets();

};

#endif //UNTITLED2_DYNAMICSTACK_H
