#include <iostream>
#include <string>

#include "DynamicStack.h"
#include "Packet.h"

using std::cout; using std::cin; using std::endl; using std::string;


DynamicStack:: DynamicStack(): top(nullptr){}

bool DynamicStack:: isEmpty(){
    return (top == nullptr);
}

void DynamicStack::push(Packet &packet){
    Node * newNode = new Node(packet);
    newNode->next = top;
    top = newNode;

    while (!isEmpty()){
        Packet processedPacket = pop();
        packetsProcessedPC.insertBeginning(processedPacket);
    }
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

void DynamicStack:: displayPackets(){
    cout << "All the Packets in the PC are: " << endl;
    Node * current = top;
    while (current != nullptr){
        cout << "Packet with data  : " << current-> data.getLabel()<<endl;
        current =current ->next;
    }
}
void DynamicStack::displayProcessedPackets(){
    packetsProcessedPC.display();
}

int DynamicStack::getTop() const {

    if (!isEmpty()) {
        return top->data.getValue();//falta implementarlo
    } else {
        cout << "PC is empty" << endl;
        return -1;
    }
}

DynamicStack::~DynamicStack()
{
    while (!isEmpty()) {
        pop();
    }
}

