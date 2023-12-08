#include "DoubleLinkedList.h"
#include "Packet.h"
#include "DynamicStack.h"
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

DoubleLinkedList::DoubleLinkedList(): head(nullptr), tail(nullptr) {}

void DoubleLinkedList::insertBeginning(Packet &packet) {

    Nodo * newNode = new Nodo(packet); //creation of new node
    if (head== nullptr){
        head= tail = newNode;
    }
    else {
        newNode->next =head;
        head ->prev =newNode;
        head =newNode;
    }
}

void DoubleLinkedList ::insertMiddle(Nodo * prev_node , Packet &packet) {

    if (prev_node == nullptr){
        cout << "El paquete en la posición anterior es el ultimo paquete de la lista"<<endl;
    }

    Nodo * newNode= new Nodo (packet);

    newNode->next = prev_node->next; //connection between the created node and the previous one
    newNode->prev =prev_node;

    if (prev_node->next!= nullptr){ //make sure we are not at the end of the list
        prev_node->next->prev = newNode; //create bidirectional link
    }

    prev_node->next = newNode;
}

void DoubleLinkedList::insertEnd(Packet &packet) {
    Nodo* newNode = new Nodo(packet);
    if (head== nullptr){
        head= tail= newNode;
    }
    else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}

Packet DoubleLinkedList::searchByID(const string &packetLabel) {

    Nodo* current = head;
    while (current!= nullptr){
        if (current->data.getLabel()==packetLabel){
            return current->data;
        }
        current= current->next;
    }
    return Packet(); // si termina el bucle y no se encuentra devolver paquete vacio
}

void DoubleLinkedList::displayPacketsForHub() {

    Nodo* current = head;

    while (current!= nullptr){

        int postalCode = current->data.getPostalCode();

        if (postalCode== 37115){
            cout << "Packet to be processed to Hub Almenara de Tormes: "<< current<< endl;
        }
        else if (postalCode== 37427){
            cout << "Packet to be processed to Hub Pedrosillo el Ralo: "<< current<< endl;
        }
        else if (postalCode== 37449){
            cout << "Packet to be processed to Hub Rodillo "<< current<< endl;
        }
        else if (postalCode== 37893){
            cout << "Packet to be processed to Hub Villagonzalo de Tormes: "<< current<< endl;
        }
        else if (postalCode== 37797){
            cout << "Packet to be processed to Hub Castellanos de Villiquera: "<< current<< endl;
        }
        else if (postalCode== 37796){
            cout << "Packet to be processed to Hub Mozárbez: "<< current<< endl;
        }
        else if (postalCode== 37129){
            cout << "Packet to be processed to Hub Barregas: "<< current<< endl;
        }
        else if (postalCode== 37340){
            cout << "Packet to be processed to Hub Aldearrubia: "<< current<< endl;
        }
        else if (postalCode== 37001){
            cout << "Packet to be processed to Hub Salamanca: "<< current<< endl;
        }
        current = current->next;
    }
}

void DoubleLinkedList:: transportPacket(Packet &packet){

    Nodo * current = head;
    while (current!= nullptr){
        if(current->data.getPostalCode()==packet.getPostalCode()){
            break;
        }
        current = current->next;
    }

    if (current== nullptr){
        cout << "Packet does not exisit in the central station"<<endl;
    }

    if (current->prev != nullptr){
        current->prev->next =current->next;
        //delete packet from list
    }
    else {
        //when the packet is in top position
        head = current->next;
    }

    if (current->next!= nullptr){
        current->next->prev = current->prev;
    }

    delete current;

    int pcPostalCode= packet.getPostalCode();
    DynamicStack *pcStack = findPC(pcPostalCode);

    if (pcStack != nullptr){
        pcStack->push(packet);
        cout << "Packet with label " <<packet.getLabel()<< "transported to PC" <<endl;
    }
    else{
        cout <<"PC in label not found in system"<< endl;
    }
}

DynamicStack* DoubleLinkedList::findPC(int pcPostalCode) {
    Hub * hub= hubInTree.search(pcPostalCode);

    if (hub != nullptr){
        DynamicStack & pcStack = hub->getStackByPostalCode(pcPostalCode);
        return &(pcStack);
    }
    else{
        return nullptr;
    }
}


DoubleLinkedList:: ~DoubleLinkedList(){
    Nodo* current = head;
    while (current != nullptr){
        Nodo* nextNode = current->next;
        delete current; //free memory of actual node
        current = nextNode; //move to next node
    }
}