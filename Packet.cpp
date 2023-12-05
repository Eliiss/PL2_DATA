#include "Packet.h"

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>

using std::cout; using std::cin; using std::endl; using std::string;

void Packet::assignLabel(){

    string digits1; //Number of the packet
    digits1 = getPacketNumber();

    string digits2; //3 random digits
    for(int i=0; i<3; i++){
        digits2 += std::to_string(rand() % 10);
    }

    string letters1; //1 random letter
    for(int i=0; i<1; i++){
        int randomNum = rand() % 25 + 65; // We create a random number between 65 ('A' in ASCII) and 90 ('Z')
        char randomChar = static_cast<char>(randomNum); //We transfrom the number to char using the ascii table
        letters1 += randomChar;
    }

    int dayi = rand() % 31 + 1; //A random day
    string day = "";
    if (dayi < 10){
        day += "0";
        day += std::to_string(dayi);
    }
    else{
        day = std::to_string(dayi);
    }

    int monthi = rand() % 12 + 1; //A random month
    string month = "";
    if (monthi < 10){
        month += "0";
        month += std::to_string(monthi);
    }
    else{
        month = std::to_string(monthi);
    }

    int yeari = rand() % 24; //A random year
    yeari += 2000;
    string year = std::to_string(yeari);

    int postalCodei = getPostalCode();
    string postalCode1 = std::to_string(postalCodei);

    label.packetLabel = digits1 + '-' + digits2 + letters1 + '-' + day + month + year + '-' + postalCode1;

}

string Packet::getLabel(){
    return label.packetLabel;
}

void Packet::assignLatitude(){

    //We create a random latitude and put it in degress, minutes and seconds

    int numlat = rand() % (2169+1);
    numlat=numlat*100;
    double latitudeRan = (static_cast<double>(numlat) / 1000000.0) + 40.854057;

    label.coordinates.latitude = latitudeRan;

    double degreeslat = int(latitudeRan);
    double minuteslat = (latitudeRan - degreeslat)*60;
    double secondslat = (minuteslat - int(minuteslat))*60;

    int degresslati = static_cast<int>(latitudeRan);
    int minuteslati = static_cast<int>(minuteslat);

    label.coordinates.latitudeS = std::to_string(degresslati) + " " + std::to_string(minuteslati) + " " + std::to_string(secondslat);

    if(latitudeRan <= 40.9625275){
        latitudeNS = 'S';
    }
    else{
        latitudeNS = 'N';
    }
}

string Packet::getLatitude(){
    return label.coordinates.latitudeS;
}

void Packet::assignLongitude(){

    //We create a random longitude and put it in degress, minutes and seconds

    int numlon = rand() % (3546+1);
    numlon = numlon*10;
    double longitudeRan = (static_cast<double>(numlon) / 100000.0) + 5.483051;

    label.coordinates.longitude = longitudeRan*(-1);

    double degreeslon = int(longitudeRan);
    double minuteslon = (longitudeRan - degreeslon)*60;
    double secondslon = (minuteslon - int(minuteslon))*60;

    longitudeRan = longitudeRan*(-1);
    degreeslon = degreeslon*(-1);
    minuteslon = int(minuteslon);

    int degressloni = static_cast<int>(longitudeRan);
    int minutesloni = static_cast<int>(minuteslon);
    label.coordinates.longitudeS = std::to_string(degressloni) + " " + std::to_string(minutesloni) + " " + std::to_string(secondslon);

    if(longitudeRan <= -5.660391){
        longitudeWE = 'W';
    }
    else{
        longitudeWE = 'E';
    }
}

string Packet::getLongitude(){
    return label.coordinates.longitudeS;
}

void Packet::assignUrgent(){

    int random = rand() % 2;

    switch (random) {
        case 0:
            urgent = true;
            break;
        case 1:
            urgent = false;
            break;
    }
    //If we print urgent in the terminal, 1 will be true and 0 false
}

bool Packet::getUrgent(){
    return urgent;
}

string Packet::getZone(){
    string zona = "";
    zona += latitudeNS;
    zona += longitudeWE;
    return zona;
}

void Packet::setStatus(t_status newStatus){
    status = newStatus;
}

t_status Packet::getStatus(){
    return status;
}

void Packet::assignDni(){

    string dnistr = "";

    for(int i=0;i<8;i++){
        dnistr += std::to_string(rand() % 10);
    }

    int dninum = std::stoi(dnistr);
    const char letrasDNI[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    int indice = dninum % 23;
    char letra = letrasDNI[indice];

    dni = dnistr + letra;
}

string Packet::getDni(){
    return dni;
}

void Packet::setPacketNumber(int n){
    packetNumber = n;
}

int Packet::getPacketNumber(){
    return packetNumber;
}

void Packet::setPostalCode(){
    int num = rand() % N2+1;
    postalCode = postalCodes[num];
}

int Packet::getPostalCode(){
    return postalCode;
}