#ifndef UNTITLED2_QUEUE_H
#define UNTITLED2_QUEUE_H


#include <iostream>
#include <string>
#include "Packet.h"

using std::cout; using std::cin; using std::endl; using std::string;

class Packet;
class Hub;

struct Node{
    Packet data;
    Node *next;
};

class Queue{
private:

    Node *rear = nullptr;
    Node *front = nullptr;

public:

    void enqueue(Packet &packet);
    bool isEmpty();
    Packet dequeue();
    void display();
    ~Queue(); // destructor
};

#endif //UNTITLED2_QUEUE_H
