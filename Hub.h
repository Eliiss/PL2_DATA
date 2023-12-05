#ifndef HUB_HPP
#define HUB_HPP

#include <iostream>
#include <string>
#include "Stack.h"


using std::cout; using std::cin; using std::endl; using std::string;


class Hub{

private:
    Stack packetInStack;

public:
    void pushPacket(Packet packet);
    Packet popPacket();
    bool isHubEmpty();
    bool isHubFull();
    void displayPacketsHub();
    void displayProcessedPacketsHub();
    int getHubTop();

};

#endif