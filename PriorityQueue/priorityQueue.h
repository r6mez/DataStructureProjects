#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H
#include <iostream>
using namespace std;

template <class t>
struct Node {
    t data;
    int priority;
    Node *next;

    Node(int val, int pri) : data(val), priority(pri), next(nullptr) {}
};

template <class t>
class PriorityQueue{
    Node<t> *head;
    int size;

public:
    PriorityQueue(){
        head = nullptr;
        size = 0;
    }

    ~PriorityQueue(){
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

    void enqueue(t val, int pri){
        // allocation
        Node<t> *newNode = new Node<t>(val, pri);

        if(head == nullptr || newNode->priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<t> *temp = head;
            while (temp->next != nullptr && newNode->priority <= temp->next->priority) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
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


#endif //PRIORITYQUEUE_PRIORITYQUEUE_H
