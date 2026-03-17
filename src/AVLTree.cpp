#include "AVLTree.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void AVLTree::drawTree(const Node * node, string tabs){
    if(!node){
        return;
    }
    if(root == node){
        cout << "Root: BF=" << node->blanceFactor << " value=" << node->value << endl; 
    }
    else if(node){
        cout << tabs << "BF=" << node->blanceFactor << " value=" << node->value << endl;
    }
    tabs += "   ";
    drawTree(node->left, tabs);
    drawTree(node->right, tabs);
}

void AVLTree::add(int value){
    Node * new_node = new Node(value);
    if(root == NULL){
        root = new_node;
        return;
    }

    Node * current = root;
    Node * parent;
    while (current)
    {
        parent = current;
        if(current->value > value){
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    new_node->parent = parent;
    if(parent->value > value){
        parent->left = new_node;
    }
    else{
        parent->right = new_node;
    }
    
    setup_BF_tree(root);
    current = parent->parent;
    while (current)
    {
        if(current->blanceFactor >1){
            if(current->left->blanceFactor <0){
                rotate_left(current->left);
            }
            current = rotate_right(current);
        }
        if(current ->blanceFactor < -1){
            if(current->right->blanceFactor >1){
                rotate_right(current->right);
            }
            current = rotate_left(current);
            
        }
        current = current->parent;
    }
}

void AVLTree::setup_BF_tree(Node * node){
    if(node){
        if(node->left == nullptr && node->right == nullptr){
            node->blanceFactor = 0;
        }
        else{
            int hight_lc = max(0,getHight(node->left)+1);
            int hight_rc = max(0,getHight(node->right)+1);

            node->blanceFactor = hight_lc - hight_rc;
            setup_BF_tree(node->left);
            setup_BF_tree(node->right);
        }
    }
}

Node * AVLTree::rotate_left(Node * node){
    if(node == nullptr){
        return nullptr;
    }

    Node * right_child = node->right;
    Node* parent = node->parent;

    //set up parent and node connection
    right_child->parent = parent;
    node->parent = right_child;
    //setup leftchild and node connection
    node->right = right_child->left;
    right_child->left = node;
    if(node->right){
        node->right->parent = node;
    }
    if(!parent){
        root = right_child;
    }
    else{
        if(parent->left == node){
            parent->left = right_child;
        } else{
            parent->right = right_child;
        }   
    }
    setup_BF_tree(root);

    return right_child;
}

Node * AVLTree::rotate_right(Node * node){
    if(node == nullptr){
        return nullptr;
    }

    Node * left_child = node->left;
    Node* parent = node->parent;
    //setup parent and LC connection
    left_child->parent = parent;
    node->parent = left_child;
    //setup right child and node connection
    node->left = left_child->right;
    left_child->right = node;
    if(node->left){
        node->left->parent = node;
    }
    if(!parent){
        root = left_child;
    }
    else{
        if(parent->left == node){
            parent->left = left_child;
        } else{
            parent->right = left_child;
        }   
    }
    setup_BF_tree(root);

    return left_child;
}

int AVLTree::getHight(Node * node){
    if(node == nullptr){
        return -1;
    }
    int leftH = getHight(node->left);
    int rightH = getHight(node->right);

    return max(leftH, rightH) + 1;
}


void AVLTree::destroy(Node * node){
    if(!node)
        return;
    
    destroy(node->left);
    destroy(node->right);
    delete node;
}