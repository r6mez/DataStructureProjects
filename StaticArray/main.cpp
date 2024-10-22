#include <iostream>
#include "StaticArray.h"
using namespace std;

int main() {
    StaticArray<int> a(20);
    for (int i = 10; i >= 1; i--) {
        a.append(i);
    }

    cout << a.getSize() << endl;
    a.displayArray();

    a.insert(3, 3);
    cout << a.binary_search(3) << endl;

    a.displayArray();

    a.delete_at(5);

    a.displayArray();

    cout << a.getSize() << endl;

    a.mergeSort();

    a.displayArray();

    return 0;
}
