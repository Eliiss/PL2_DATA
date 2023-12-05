#include <iostream>
#include <time.h>

#include "CentralStation.h"

using std::cout; using std::cin; using std::endl;

int main() {
    CentralStation centralStation;
    Hub* hub = nullptr;

    int choice, number;
    int seed = time(NULL);
    
    string townAbbreviations[N2] = {"ADT", "PER", "ROD", "VDT", "CDV", "MOZ", "CDB", "ALD", "SAL"};
    string townNames[N2] = {"Almenara de Tormes", "Pedrosillo el Ralo", "Rodillo", "Villagonzalo de Tormes",
                                "Castellanos de Villiquera", "Mozárbez", "Barregas", "Aldearrubia", "Salamanca"};
    
    PacketIdentification::Coordinates townCoordinates[N2] =  {{41.063731, -5.822845},
                                                                    {41.062078, -5.549428}, 
                                                                    {40.904379, -5.817114},
                                                                    {40.892617, -5.497089},
                                                                    {41.051809, -5.695013},
                                                                    {40.858588, -5.651533},
                                                                    {40.989969, -5.754544},
                                                                    {41.007675, -5.499685},
                                                                    {40.965093, -5.660631}};
    
    for(int i=0;i<5;i++){
    Packet packet;
    int num=1;
    seed+=i;
    srand(seed);
    packet.setPacketNumber(num);
    packet.setPostalCode();
    packet.assignLatitude();
    packet.assignLongitude();
    packet.assignLabel();
    packet.assignUrgent();
    packet.assignDni();
    packet.setStatus(PROCESSING);
    
    cout << packet.getLongitude() << " " << packet.getLabel() << endl;
    }
    
    //logistics.initialise();
    
    while (true) {

        cout << '\n' << "-------------------Parcel Service Menu----------------------" << endl;
        cout << "[1]. See data of next packet to be delivered" << endl;
        cout << "[2]. See statistics" << endl;
        cout << "[3]. Search packet by ID" << endl;
        cout << "[4]. Delete a packet from a PC" << endl;
        cout << "[5]. Transport a packet from the SPCS to a PC" << endl;
        cout << "[6]. Transport a packet from a PC to another PC" << endl;
        cout << "[7]. Carry on with the packet's delivery" << endl;
        cout << '\n' << "[0]. EXIT" << endl;
        cout << "------------------------------------------------------------" << '\n' << endl;
        cout << "Introduce an instruction: ";
        cin >> choice;

        switch (choice) {
            case 1:
                //hub = logistics.getSelectedPC();
                //logistics.showNextPacket(hub);
                break;
            case 2:
                //logistics.showStatistics();
                break;
            case 3:
                //packet = logistics.searchPacket();
                break;
            case 4:
                //hub = logistics.getSelectedPC();
                //logistics.removePacket(hub);
                break;
            case 5:
                //hub = logistics.getSelectedPC();
                //packet = logistics.searchPacket();
                //logistics.transportPacket(packet, hub);
                break;
            case 6:
                //hub = logistics.getSelectedPC();
                //packet = logistics.searchPacket();
                //logistics.movePCPacket(packet, hub);
                break;
            case 7:
                //logistics.carryOnDelivery();
                break;
            case 0:
                cout << '\n' << "Shutting down Parcel Service Simulator" << endl;
                return 0; //The menu is closed
            default:
                cout << "Invalid option. Please, insert a valid option." << endl;
        }
    }
}