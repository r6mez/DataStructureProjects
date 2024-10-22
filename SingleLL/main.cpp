#include <iostream>
#include "SingleLL.h"
using namespace std;

int main() {
    SingleLL<int> ls;
    ls.insert_at_begin(1);
    ls.insert_at_end(2);
    ls.insert_at_end(3);
    ls.insert_at_end(4);
    ls.insert_at_end(5);

    ls.traverse();

    ls.insert_at(6, 3);
    ls.insert_at(0, 0);

    ls.traverse();

    ls.delete_at_begin();

    ls.traverse();

    ls.delete_at_end();

    ls.traverse();

    ls.delete_at(2);

    ls.traverse();

    cout << "Size: " << ls.getSize() << endl;
}
