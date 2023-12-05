#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
#include "Packet.h"

using std::cout; using std::cin; using std::endl; using std::string;

class Packet;
class Queue;

class Stack{

    private:
        int top;
        static const int MAX_PACKETS = N3;
        Packet packets [MAX_PACKETS];
        Queue packetsProcessedHub;

    public:
        Stack();
        bool isEmpty() const;
        bool isFull() const;
        void push(Packet packet);
        Packet pop();
        void displayPacketsStack();
        void displayProcessedPackets();
        int getTop();

};

#endif