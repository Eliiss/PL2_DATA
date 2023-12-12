#ifndef UNTITLED2_LOGISTICS_H
#define UNTITLED2_LOGISTICS_H
#include <iostream>
#include <string>
#include "CentralStation.h"

using std::cout; using std::cin; using std::endl; using std::string;

class Logistics{

private:
    AVL hubInTree;
    Hub hub;
    CentralStation centralStation;


public:
    void initialise();
    Hub getSelectedPC();
    void showNextPacket();
    void showStatistics();
    Packet searchPacket();
    void removePacket(Hub hub);
    void transportPacket(Packet packet);
    void movePCPacket();
    void carryOnDelivery();
};
#endif //UNTITLED2_LOGISTICS_H
