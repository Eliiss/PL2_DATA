#ifndef UNTITLED2_DYNAMICSTACK_H
#define UNTITLED2_DYNAMICSTACK_H

#include <iostream>
#include "Packet.h"
#include "DoubleLinkedList.h"

using std::cout; using std::cin; using std::endl; using std::string;

struct Node; //reutilizamos el nodo en queue

class DynamicStack{

private:
    Node* top;
    DoubleLinkedList packetsProcessedPC;

public:
    DynamicStack();
    bool isEmpty();
    void push(Packet &packet);
    Packet pop ();
    void displayPackets();
    void displayProcessedPackets();
    int getTop() const;
    ~DynamicStack();

};

#endif //UNTITLED2_DYNAMICSTACK_H
