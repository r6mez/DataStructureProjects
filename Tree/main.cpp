#include <iostream>
#include "binaryTree.h"
#include "binarySearchTree.h"
using namespace std;

int main() {
    BinaryTree BT;
    BT.insert(1);
    BT.insert(2);
    BT.insert(3);
    BT.insert(4);
    BT.insert(5);

    BT.inorder();

    int key = 50;
    if(BT.searchDFS(key)){
        cout << "Found: " << key << "\n";
    } else {
        cout << "Not Found\n";
    }

    BinarySearchTree BST;
    BST.insert(10);
    BST.insert(20);
    BST.insert(30);
    BST.insert(40);
    BST.insert(50);
    BST.insert(60);
    BST.insert(70);
    BST.insert(80);

    BST.preorder();

    if(BST.search(key)){
        cout << "Found: " << key << "\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}
