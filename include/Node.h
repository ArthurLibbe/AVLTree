#ifndef __Node_H
#define __Node_H

struct Node
{
    Node * left;
    Node * right;
    Node* parent;
    int value;
    int blanceFactor;
    Node(int value) : value(value), left(nullptr), right(nullptr), parent(nullptr), blanceFactor(0){};
};

#endif