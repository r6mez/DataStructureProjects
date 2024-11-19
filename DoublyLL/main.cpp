#include <iostream>
#include "DoublyLL.h"
using namespace std;

int main() {
    DoubleLL<int> dll;
    dll.insert_at_begin(10);
    dll.traverse();
    dll.insert_at_begin(20);
    dll.traverse();
    dll.insert_at_end(30);
    dll.traverse();
    dll.insert_at(50, 2);
    dll.traverse();
    dll.insert_at(40, 1);
    dll.traverse();
    dll.insert_at(60, 4);
    dll.traverse();
    dll.delete_at_begin();
    dll.traverse();
    dll.delete_at_end();
    dll.traverse();
    dll.delete_at(3);

    return 0;
}
