#ifndef SINGLELL_H
#define SINGLELL_H
#include <iostream>
using namespace std;

template <class t>
struct Node {
    t data;
    Node *next;

  Node(int val) : data(val), next(nullptr) {}
};

template <class t>
class SingleLL {
    private:
        Node<t> *head;
        int size;

    public:
        SingleLL() : head(nullptr), size(0) {}

        ~SingleLL(){
            clear();
        }

        void traverse() const {
            Node<t> *current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        bool search(t val) const {
            Node<t> *current = head;
            while (current != nullptr) {
                if(current->data == val) {
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
            Node<t>* current = head;
            while (current != nullptr) {
                Node<t> *temp = current->next;
                delete current;
                current = temp;
            }
            head = nullptr;
            size = 0;
        }

        void insert_at_begin(t val) {
            Node<t> *newNode = new Node<t>(val);
            newNode->next = head;
            head = newNode;
            size++;
        }

        void insert_at_end(t val) {
            if(head == nullptr) {
                head = new Node<t>(val);
                return;
            }

            Node<t> *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = new Node<t>(val);

            size++;
        }

        void insert_at(t val, int index) {
            if(index >= size || index < 0) {
                throw out_of_range("index out of range");
            }

            if(index == 0) {
                insert_at_begin(val);
                return;
            }

            Node<t>* newNode = new Node<t>(val);
            Node<t>* temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;

            size++;
        }

        void delete_at_begin() {
            if(head == nullptr) {
                cout << "Empty list" << endl;
                return;
            }
            Node<t> *temp = head;
            head = head->next;
            delete temp;
            size--;
        }

        void delete_at_end() {
            if(head == nullptr) {
                cout << "Empty list" << endl;
                return;
            }

            if(head->next == nullptr) {
                delete head;
                head = nullptr;
                size--;
                return;
            }

            Node<t> *temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }

            delete temp->next;
            temp->next = nullptr;
            size--;
        }

        void delete_at(int index) {
            if(index >= size || index < 0) {
                throw out_of_range("index out of range");
            }

            if(index == 0) {
                delete_at_begin();
            } else if(index == size - 1) {
                delete_at_end();
            } else {
                Node<t>* temp = head;
                for (int i = 1; i < index; i++) {
                    temp = temp->next;
                }
                Node<t> *Nt = temp->next;
                temp->next = Nt->next;
                delete Nt;

                size--;
            }
        }
};



#endif //SINGLELL_H
