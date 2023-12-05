#include "Util.h"

#include <iostream>


using std::cout; using std::cin; using std::endl; using std::string;

PacketIdentification::Coordinates Util::getCoordinatesForCity(const int &cityAbbreviation) const {
    PacketIdentification :: Coordinates coordinates;

    //asociamos las coordenadas de cada acronimo a una ciudad especifica
    for (int i = 0 ; i< N2; i++){
        if (townAbbreviations[i] == cityAbbreviation){
            coordinates = townCoordinates[i];
            break;
        }
    }
    return coordinates;
}

//Para la memoria : La funcion getCoordinatesForCity se realiza para obtener las coordenadas asociadas
//al acronimo de una ciudad. Es previamente usada en la implementacion de otras estructuras de datos
//como la double link list para ayudar en la busqueda de un paquete especifico o para saber que paquetes deben
//ser distribuidas a cada pc