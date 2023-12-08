#ifndef UNTITLED2_LOGISTICS_H
#define UNTITLED2_LOGISTICS_H
#ifndef Logistics_h


#include <iostream>
#include <string>
#include "CentralStation.h"

using std::cout; using std::cin; using std::endl; using std::string;

class Logistics{

private:
    AVL hubInTree;

public:
    void initialise();
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
#endif //UNTITLED2_LOGISTICS_H
