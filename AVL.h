#ifndef UNTITLED2_AVL_H
#define UNTITLED2_AVL_H
#include "Hub.h"

class AVLNode {

public:
    int postalCode;
    Hub hub;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int postalCode, const Hub& hub);
};

class AVL {
private:
    AVLNode* root;

    AVLNode* insert(AVLNode* node, int postalCode, const Hub& hub);
    AVLNode* search(AVLNode* node, int postalCode);

public:
    AVL();
    void insert(int postalCode, const Hub& hub);
    Hub* search(int postalCode);
};

#endif //UNTITLED2_AVL_H
