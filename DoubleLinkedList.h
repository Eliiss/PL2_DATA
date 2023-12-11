#ifndef UNTITLED2_DOUBLELINKEDLIST_H
#define UNTITLED2_DOUBLELINKEDLIST_H

#include <iostream>
#include <string>
#include "Packet.h"
#include "DynamicStack.h"
#include "AVL.h"

using std::cout; using std::cin; using std::endl; using std::string;

struct Nodo{
    Packet data;
    Nodo *next;
    Nodo *prev;
    Nodo(Packet &packet): data(packet), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList{
private:
    Nodo *head;
    Nodo *tail;
    AVL hubInTree;
    int packetsInHub;
    DynamicStack packetProcessed;



public:
    DoubleLinkedList();
    void insertBeginning(Packet &packet);
    void insertMiddle(Nodo* prev_node, Packet &packet);
    void insertEnd(Packet &packet);
    Packet searchByID(const string &id);
    void displayPacketsForHub();
    void transportPacket(Packet &packet);
    void process();
    DynamicStack* findPC(int pcPostalCode);
    ~DoubleLinkedList();

};

#endif //UNTITLED2_DOUBLELINKEDLIST_H
