#include "AVL.h"
#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;


AVLNode::AVLNode(int postalCode, const Hub& hub)
        : postalCode(postalCode), hub(hub), left(nullptr), right(nullptr), height(1) {}

AVL::AVL() : root(nullptr) {}

int getHeight(AVLNode* node) {
    if (node == nullptr){
        return 0;
    }
    return node->height;
}

int getBalance(AVLNode* node) {
    if (node == nullptr){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

int max (int a, int b){
    return (a>b)? a:b;
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    //rotation
    x->right = y;
    y->left = T2;

    //update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    //return new root
    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y;
}

AVLNode* AVL::insert(AVLNode* node, int postalCode, const Hub& hub) {

    //Binary tree insertion
    if (node == nullptr) {
        return new AVLNode(postalCode, hub);
    }

    if (postalCode < node->postalCode) {
        node->left = insert(node->left, postalCode, hub);
    } else if (postalCode > node->postalCode) {
        node->right = insert(node->right, postalCode, hub);
    } else {
        // we can not have the same postalCode not allowed in bst
        return node;
    }

    //upgrade height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left, Left Case
    if (balance > 1 && postalCode < node->left->postalCode) {
        return rightRotate(node);
    }

    // Right, Right Case
    if (balance < -1 && postalCode > node->right->postalCode) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && postalCode > node->left->postalCode) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && postalCode < node->right->postalCode) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* AVL::search(AVLNode* node, int postalCode) {
    //when node is null or the postal code is found
    if (node == nullptr || node->postalCode == postalCode) {
        return node;
    }

    //recursive search in subtrees
    if (postalCode < node->postalCode) {
        return search(node->left, postalCode);
    }


    return search(node->right, postalCode);
}
AVLNode* AVL::getRoot(){
    return root;
}

void AVL::insert(int postalCode, const Hub& hub) {
    root = insert(root, postalCode, hub);
}

Hub* AVL::search(int postalCode) {
    AVLNode* node = search(root,postalCode);

    if (node!= nullptr){
        return &(node->hub);
    } else{
        return nullptr;
    }
}


void AVL::searchPacketInAllHubs(AVLNode* node, const string& packetLabel) {
    if (root != nullptr) {
        searchPacketInAllHubs(root, packetLabel);
    } else {
        cout << "The AVL tree is empty." << endl;
    }
    if (node != nullptr) {
        searchPacketInHub(node->hub, packetLabel);
        searchPacketInAllHubs(node->left, packetLabel);
        searchPacketInAllHubs(node->right, packetLabel);
    }
}

Packet AVL:: searchPacketInHub(Hub& hub, const string& packetLabel) {
    return hub.searchPacketHub(packetLabel);
}