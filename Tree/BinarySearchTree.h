#ifndef TREE_BINARYSEARCHTREE_H
#define TREE_BINARYSEARCHTREE_H
#include <iostream>
#include <queue>
using namespace std;

class BinarySearchTree {
    Node* root;

    void preorder(Node *node){
        if(node == nullptr){
            return;
        }

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node *node){
        if(node == nullptr){
            return;
        }


        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node *node){
        if(node == nullptr){
            return;
        }


        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // helper function
    void insert(Node* node ,int key){
        // If the tree is empty, create the root
        if (root == nullptr) {
            root = new Node(key);
            return;
        }

        // BST allows no repetition, so if the value already exists, we do nothing
        if (key == node->data) {
            return;
        } else if (key < node->data) {
            // If left child is null, create a new node
            if (node->left == nullptr) {
                node->left = new Node(key);
            } else {
                // Recur for the left subtree
                insert(node->left, key);
            }
        } else { // key > node->data
            // If right child is null, create a new node
            if (node->right == nullptr) {
                node->right = new Node(key);
            } else {
                // Recur for the right subtree
                insert(node->right, key);
            }
        }
    }

    // Helper function
    bool search(Node* node, int key) {
        // Base case: If the node is null, the key is not found
        if (node == nullptr) {
            return false;
        }

        // If the key matches the current node's data, it is found
        if (key == node->data) {
            return true;
        }

        // Recur to the left subtree if the key is smaller
        if (key < node->data) {
            return search(node->left, key);
        } else { // Recur to the right subtree if the key is larger
            return search(node->right, key);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(Node *node) : root(node) {}

    void preorder(){
        preorder(root);
        cout << endl;
    }

    void inorder(){
        inorder(root);
        cout << endl;
    }

    void postorder(){
        postorder(root);
        cout << endl;
    }

    void BFS(Node *root){
        if(root == nullptr) return;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            cout << node->data << " ";
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
    }

    void insert(int key){
        insert(root, key);
    }

    bool search(int key){
        return search(root, key);
    }
};
#endif //TREE_BINARYSEARCHTREE_H
