#include <iostream>
#include <string>
#include "DynamicStack.h"
#include "Packet.h"
#include "AVL.h"

class AVL;
using std::cout; using std::cin; using std::endl; using std::string;


DynamicStack:: DynamicStack(): top(nullptr){}

bool DynamicStack:: isEmpty(){
    return (top == nullptr);
}

int DynamicStack::getSize() const {
    int count = 0;
    Node* current = top;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

void DynamicStack::push(Packet &packet){
    Node * newNode = new Node(packet);
    newNode->next = top;
    top = newNode;
}

Packet DynamicStack:: pop (){
    if (isEmpty()){
        cout << "PC EMPTY" <<endl;
        return Packet();
    }
    else{
        Node* temp = top;
        Packet deliveredPacket = temp->data;
        top = top-> next;
        delete temp;

        deliveredPacket.setStatus(DELIVERED);
        return (deliveredPacket);
    }
}
void DynamicStack::process() {
    int packetsToProcess= N4;

    if (getSize()<N4){
        cout<< "Not enough packets to process in the Hub"<<endl;
    }

    cout << "Processing " << packetsToProcess << " packets..." << endl;

    while (packetsToProcess >0 ){

        Packet processedPacket = pop();
        packetsProcessedHub.enqueue(processedPacket);
        cout << "Processing Packet " << processedPacket.getLabel() << endl;
        packetsToProcess--;

    }
}

Packet DynamicStack::searchPacket(const string &packetLabel) {
    Node* current = top;
    while (current!= nullptr){
        if (current->data.getLabel()==packetLabel){
            return current->data;
        }
        current= current->next;
    }
    return Packet();
}

bool DynamicStack::movePacket(AVL&  hubsTree, const string &packetLabel) {
    if (!isEmpty()) {
        Packet packet = searchPacket(packetLabel);
        if (packet.getLabel() == packetLabel) {
            cout << "Choose the destination hub (Enter hub postal code): ";
            int destinationPostalCode;
            cin >> destinationPostalCode;

            Hub* destinationHub = hubsTree.search(destinationPostalCode);

            if (destinationHub != nullptr) {
                destinationHub->pushHub(packet);
                deletePacket(packetLabel);
                cout << "Packet '" << packetLabel << "' moved to destination Hub " << destinationHub->getPc().abbreviation << "." << endl;
                return true;
            } else {
                cout << "Hub with postal code " << destinationPostalCode << " not found." << endl;
            }
        } else {
            cout << "Packet '" << packetLabel << "' not found in current PC." << endl;
        }
    } else {
        cout << "Hub is empty. No packet to move." << endl;
    }
    return false;
}

void DynamicStack::deletePacket(const string &packetLabel) {

    Node *current = top;
    Node *prev = nullptr;

    while (current != nullptr) {
        if (current->data.getLabel() == packetLabel) {
            if (prev == nullptr) {
                // when Packet is at the top of the stack
                top = current->next;
            } else {
                // when Packet is in the middle or at the bottom of the stack
                prev->next = current->next;
            }
            delete current;
            cout << "Packet '" << packetLabel << "' deleted from the PC." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Packet '" << packetLabel << "' not found in the PC." << endl;
}

void DynamicStack:: displayPackets(){
    cout << "All the Packets in the PC are: " << endl;
    Node * current = top;
    while (current != nullptr){
        cout << "Packet with data  : " << current-> data.getLabel()<<endl;
        current =current ->next;
    }
}
void DynamicStack::displayProcessedPackets(){
    packetsProcessedHub.display();
}

DynamicStack::~DynamicStack()
{
    while (!isEmpty()) {
        pop();
    }
}

