//
// Created by irame on 11/19/2024.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <iostream>
using namespace std;

template <class t>
struct Node {
    t data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

template <class t>
class Stack{
    Node<t> *head;
    int size;

public:
    Stack(){
        head = nullptr;
        size = 0;
    }

    ~Stack(){
        clear();
    }


    void clear() {
        Node<t>* current = head;
        while (current != nullptr) {
            Node<t> *temp = current->next;
            delete current;
            current = temp;
        }
        head = nullptr;
        size = 0;
    }

    void traverse() const {
        Node<t> *current = head;
        // until not reached the last node
        while (current != nullptr) {
            cout << current->data << " ";
            // move pointer to the next node
            current = current->next;
        }
        cout << endl;
    }

    void push(t val){
        // allocation
        Node<t> *newNode = new Node<t>(val);

        if(head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(){
        if(head == nullptr){
            cout << "Stack is empty!\n";
        } else {
            Node<t> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void top(){
        if(head == nullptr){
            cout << "Stack is empty!\n";
        } else {
            cout << head->data << "\n";
        }
    }
};

#endif //STACK_STACK_H
