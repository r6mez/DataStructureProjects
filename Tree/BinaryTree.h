#ifndef TREE_BINARYTREE_H
#define TREE_BINARYTREE_H
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = right = nullptr;
    }

    ~Node(){
        delete left;
        delete right;
    }
};

class BinaryTree {
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

    // Helper Function
    bool searchDFS(Node* parent, int key){
        // if the current node is null then we reached the leaf
        if (parent == nullptr) return false;

        // If the node's data is equal to the value we are searching for
        if (parent->data == key) return true;

        // Recursively search in the left and right subtrees
        bool left_res = searchDFS(parent->left, key);
        bool right_res = searchDFS(parent->right, key);

        return left_res || right_res;
    }

public:
    BinaryTree() : root(nullptr) {}
    BinaryTree(Node *node) : root(node) {}

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
        // if the tree is empty create the root
        if(root == nullptr){
            root = new Node(key);
            return;
        }

        // Create a queue for level order traversal (BFS)
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            // if left is empty insert at left else push the left in the queue
            if(temp->left == nullptr){
                temp->left = new Node(key);
                break;
            } else {
                q.push(temp->left);
            }

            // if right is empty insert at right else push the right in the queue
            if(temp->right == nullptr){
                temp->right = new Node(key);
                break;
            } else {
                q.push(temp->right);
            }
        }
    }

    bool searchDFS(int key){
        return searchDFS(root, key);
    }
};


#endif //TREE_BINARYTREE_H
