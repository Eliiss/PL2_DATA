#ifndef UNTITLED2_PACKET_H
#define UNTITLED2_PACKET_H

#include <iostream>
#include <string>
#include "Util.h"

using std::cout; using std::cin; using std::endl; using std::string;

class Packet{
private: // Attributes
    PacketIdentification label;
    char latitudeNS;
    char longitudeWE;
    bool urgent;
    t_status status;
    string dni;
    int packetNumber;
    int postalCode = 0;
public: // Methods
    void assignLabel();
    string getLabel();
    void assignLatitude();
    string getLatitude();
    void assignLongitude();
    string getLongitude();
    void assignUrgent();
    bool getUrgent();
    string getZone();
    void setStatus(t_status status);
    t_status getStatus();
    void assignDni();
    string getDni();
    void setPacketNumber(int num);
    int getPacketNumber();
    void setPostalCode();
    int getPostalCode();

};

#endif
