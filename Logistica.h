#ifndef UNTITLED2_LOGISTICA_H
#define UNTITLED2_LOGISTICA_H
#include <iostream>
#include <string>
#include "CentralStation.h"

using std::cout; using std::cin; using std::endl; using std::string;

class Logistics{

private:


public:
    Hub getSelectedPC();
    void showNextPacket(Hub hub);
    void showStatistics();
    Packet searchPacket();
    void removePacket(Hub hub);
    void transportPacket(Packet packet, Hub hub);
    void movePCPacket(Packet packet, Hub hub);
    void carryOnDelivery();
};

#endif
#endif //UNTITLED2_LOGISTICA_H
