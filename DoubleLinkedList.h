#ifndef UNTITLED2_DOUBLELINKEDLIST_H
#define UNTITLED2_DOUBLELINKEDLIST_H

#include <iostream>
#include <string>
#include "Packet.h"
#include "PCs.h"

using std::cout; using std::cin; using std::endl; using std::string;

struct Node{
    Packet data;
    Node *next;
    Node *prev;
    Node(Packet &packet): data(packet), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList{
private:
    Node *head;
    Node *tail;
    PCs pc [9];

public:
    DoubleLinkedList();
    void insertBeginning(Packet &packet);
    void insertMiddle(Node* prev_node, Packet &packet);
    void insertEnd(Packet &packet);
    Packet searchByID(const string &id);
    void deleteByID(const string &id);
    void displayPacketsForPC();
    void transportPacket(Packet &packet);
    ~DoubleLinkedList();

};

#endif //UNTITLED2_DOUBLELINKEDLIST_H
