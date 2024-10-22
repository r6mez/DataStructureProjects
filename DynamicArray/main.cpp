#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main() {
    DynamicArray<int> a(20);
    for (int i = 10; i >= 1; i--) {
        a.append(i);
    }

    cout << a.getSize() << endl;
    a.display();

    a.insert(3, 3);

    a.mergeSort();
    cout << a.binary_search(3) << endl;

    a.display();

    a.delete_at(5);

    a.display();

    cout << a.getSize() << endl;

    a.mergeSort();

    a.display();

    return 0;
}
