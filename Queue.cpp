#include "Queue.h"
#include "Packet.h"

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;


bool Queue::isEmpty() {
    return front== nullptr;
}

void Queue::enqueue(Packet &packet){
    Node *temp = new Node(packet);
    temp->data = packet;
    temp->next=nullptr;

    if(rear==nullptr){ //if queue empty both point to the same element

        rear=temp;
        front=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

Packet Queue::dequeue(){

    Node *temp=front;
    Packet dequeuedPacket = front->data; //saving de data inside before removing 
    front=front->next;
    delete temp;
    if (isEmpty()) {
        rear=nullptr;
    }
    return dequeuedPacket;
}

void Queue::display(){

    Node *temp=front;
    while(temp!=nullptr){

        Packet packet = temp-> data;

        int statusi = packet.getStatus();
        string status;
        switch(statusi){
            case 0:
                packet.setStatus(PROCESSING);
                break;
            case 1:
                packet.setStatus(DELIVERING);
                break;
            case 2:
                packet.setStatus(DELIVERED);
                break;
        }

        cout << "Processing packet ID: " << packet.getLabel() << " for delivery to zone: " << packet.getZone() << endl;
        cout << "Latitude: " << packet.getLatitude() << " Longitude: " << packet.getLongitude() << endl;
        cout << "Urgent [0:no 1:yes]:" << packet.getUrgent() << ", Client DNI: " << packet.getDni() << ", Status: " << status << endl;
        cout << "----------------------------------------------------------------------------------" << endl;

        temp=temp->next;
    }
}

Queue::~Queue(){

    while(front!=nullptr){

        Node *temp=front;
        front=front->next;
        delete temp;
    }
}