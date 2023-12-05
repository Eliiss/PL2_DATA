#ifndef UNTITLED2_UTIL_H
#define UNTITLED2_UTIL_H
#define N1 4700 // Initial set of packets for the SPCS
#define N2 9 // Number of Packet Centers (PCs)
#define N3 197 // Number of packets sent from SPCS to PCs
#define N4 86 // Number of packets to deliver
#include "string"
#include "iostream"

using std::cout; using std::cin; using std::endl; using std::string;

struct PacketIdentification{

    string packetLabel;
    string clientId;

    struct Coordinates{
        double latitude;
        double longitude;
        string latitudeS;
        string longitudeS;
    } coordinates;
};

typedef enum {
    PROCESSING,
    DELIVERING,
    DELIVERED
} t_status;

class Util{
private: //Atributes
    string townAbbreviations[N2] = {"ADT", "PER", "ROD", "VDT", "CDV", "MOZ", "CDB", "ALD", "SAL"};
    string townNames[N2] = {"Almenara de Tormes", "Pedrosillo el Ralo", "Rodillo", "Villagonzalo de Tormes",
                            "Castellanos de Villiquera", "MozÃ¡rbez", "Barregas", "Aldearrubia", "Salamanca"};
    int postalCodes[N2] = {37115, 37427, 37449, 37893, 37797, 37796, 37129, 37340, 37001};
    PacketIdentification::Coordinates townCoordinates[N2] =  {{41.063731, -5.822845},
                                                              {41.062078, -5.549428},
                                                              {40.904379, -5.817114},
                                                              {40.892617, -5.497089},
                                                              {41.051809, -5.695013},
                                                              {40.858588, -5.651533},
                                                              {40.989969, -5.754544},
                                                              {41.007675, -5.499685},
                                                              {40.965093, -5.660631}};
public:
    PacketIdentification::Coordinates getCoordinatesForCity (const string & townAbbreviation)const;

};
#endif //UNTITLED2_UTIL_H
