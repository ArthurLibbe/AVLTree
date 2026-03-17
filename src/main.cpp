#include <AVLTree.h>
#include <vector>

using namespace std;

int main(){

    vector<int> v = {4,7,15,20,22,16,9,11,2};
    AVLTree * tree = new AVLTree();
    for(auto &i : v){
        tree->add(i);
    }
    string s = "";
    tree->drawTree(tree->root, s);
    delete tree;
    return 0;
}