#include "DoubleLinkedList.h"
#include "Packet.h"
#include "PCs.h"
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

DoubleLinkedList::DoubleLinkedList(): head(nullptr), tail(nullptr) {}

void DoubleLinkedList::insertBeginning(Packet &packet) {

    Node * newNode = new Node(packet); //creamos una nueva celda
    if (head== nullptr){
        head= tail = newNode;
    }
    else {
        newNode->next =head;
        head ->prev =newNode;
        head =newNode;
    }
}

void DoubleLinkedList ::insertMiddle(Node * prev_node , Packet &packet) {

    if (prev_node == nullptr){
        cout << "El paquete en la posición anterior es el ultimo paquete de la lista"<<endl;
    }

    Node * newNode= new Node (packet);

    newNode->next = prev_node->next; //conexion entre el nodo creado y el ountero delnodo previo a este
    newNode->prev =prev_node;

    if (prev_node->next!= nullptr){ //verificamos que no estamos en el ultimo nodo de la lista
        prev_node->next->prev = newNode; //hacemos el enlace bidireccional
    }

    prev_node->next = newNode;
}

void DoubleLinkedList::insertEnd(Packet &packet) {
    Node* newNode = new Node(packet);
    if (head== nullptr){
        head= tail= newNode;
    }
    else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}

Packet DoubleLinkedList::searchByID(const string &id) {

    Node* current = head;
    while (current!= nullptr){
        if (current->data.getLabel()==id){
            return current->data;
        }
        current= current->next;
    }
    return Packet(); // si termina el bucle y no se encuentra devolver paquete vacio
}

void DoubleLinkedList::deleteByID(const string &id) {

    Node* current = head;
    while (current!= nullptr && current->data.getLabel() != id){
        current= current->next;
    }

    //gestion de los posibles casos despues del bucle
    if (current==nullptr){
        cout<<"No se puede elimanr el paquete proporcionado ya que no existe" <<endl;
    }
    if (current == head){
        head= current->next; //para no perder la cabecera
    }

    //eliminamos los enlaces del nodo a quitar
    if (current->prev!= nullptr){
        current->prev->next = current->next;
    }

    if (current->next!= nullptr){
        current->next->prev=current->prev;
    }
    delete current; // eliminamos de la memoria el nodo
    cout<<"Paquete con ID "<< id <<"eliminado correctamente"<<endl;
}

void DoubleLinkedList::displayPacketsForPC() {
    Node* current = head;

    while (current!= nullptr){
        if (current->data.getPostalCode()== 37115){

        }

    }


}

void DoubleLinkedList:: transportPacket(Packet &packet){

}



DoubleLinkedList:: ~DoubleLinkedList(){
    Node* current = head;
    while (current != nullptr){
        Node* nextNode = current->next;
        delete current; //libera la memoria del nodo actual
        current = nextNode; //avanza al siguiente nodo
    }
}