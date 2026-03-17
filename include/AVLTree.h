#ifndef __AVL_TREE_H

#include "Node.h"
#include <vector>
#include <string>

class AVLTree{
    public:
        Node *root = nullptr;
        AVLTree(){}

        void add(int value);

        Node * rotate_left(Node *);
        Node * rotate_right(Node *);

        void setup_BF_tree(Node * node);
        int getHight(Node * node);
        
        void drawTree(const Node * node, std::string tabs);
        void destroy(Node * node);
        ~AVLTree(){
            destroy(root);
        }
};

#endif