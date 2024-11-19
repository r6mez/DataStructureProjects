#ifndef DOUBLYLL_DOUBLYLL_H
#define DOUBLYLL_DOUBLYLL_H
#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};


template <class T>
class DoubleLL {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoubleLL() : head(nullptr), tail(nullptr), size(0) {}

    ~DoubleLL() {
        clear();
    }

    T getHead(){
        return head->data;
    }

    T getTail(){
        return tail->data;
    }

    void traverse() const {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reverse_traverse() const {
        Node<T>* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    bool search(T val) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current->next;
            delete current;
            current = temp;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insert_at_begin(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insert_at_end(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insert_at(T val, int index) {
        if (index > size || index < 0) {
            throw out_of_range("Index out of range");
        }

        if (index == 0) {
            insert_at_begin(val);
        } else if (index == size) {
            insert_at_end(val);
        } else {
            Node<T>* newNode = new Node<T>(val);
            Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;

            size++;
        }
    }

    void delete_at_begin() {
        if (head == nullptr) {
            cout << "Empty list" << endl;
            return;
        }
        Node<T>* temp = head;
        if (head == tail) { // Only one element
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void delete_at_end() {
        if (tail == nullptr) {
            cout << "Empty list" << endl;
            return;
        }
        Node<T>* temp = tail;
        if (head == tail) { // Only one element
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    void delete_at(int index) {
        if (index >= size || index < 0) {
            throw out_of_range("Index out of range");
        }

        if (index == 0) {
            delete_at_begin();
        } else if (index == size - 1) {
            delete_at_end();
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            size--;
        }
    }
};



#endif //DOUBLYLL_DOUBLYLL_H
