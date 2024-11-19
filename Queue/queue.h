#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include <iostream>
using namespace std;

template <class t>
struct Node {
    t data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

template <class t>
class Queue{
    Node<t> *head;
    Node<t> *tail;
    int size;

public:
    Queue(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~Queue(){
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
        tail = nullptr;
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

    void enqueue(t val){
        // allocation
        Node<t> *newNode = new Node<t>(val);

        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue(){
        if(head == nullptr){
            cout << "Queue is empty!\n";
        } else {
            Node<t> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void top(){
        if(head == nullptr){
            cout << "Queue is empty!\n";
        } else {
            cout << head->data << "\n";
        }
    }
};


#endif //QUEUE_QUEUE_H
