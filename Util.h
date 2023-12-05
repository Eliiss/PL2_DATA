#define N1 4700 // Initial set of packets for the SPCS
#define N2 9 // Number of Packet Centers (PCs)
#define N3 197 // Number of packets sent from SPCS to PCs
#define N4 86 // Number of packets to deliver

using std::cout; using std::cin; using std::endl; using std::string;
int postalCodes[N2] = {37115, 37427, 37449, 37893, 37797, 37796, 37129, 37340, 37001};

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

