#include <iostream>
#include <string>
#include "Hub.h"
#include "Packet.h"
using std::cout; using std::cin; using std::endl; using std::string;

void Hub::pushPacket(Packet packet){
    packetInStack.push(packet);
}

Packet Hub::popPacket(){
    packetInStack.pop();
}

bool Hub::isHubEmpty(){
    packetInStack.isEmpty();
}

bool Hub::isHubFull(){
    packetInStack.isFull();
}

void Hub::displayPacketsHub(){
    packetInStack.displayPacketsStack();
}

void Hub::displayProcessedPacketsHub(){
    packetInStack.displayProcessedPackets();
}

int Hub::getHubTop(){
    packetInStack.getTop();
}