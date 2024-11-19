#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> s;
    s.push(10);
    s.traverse();
    s.push(5);
    s.traverse();
    s.push(7);
    s.traverse();
    s.push(9);
    s.traverse();
    s.pop();
    s.traverse();
    s.pop();
    s.traverse();
    s.pop();
    s.traverse();
    s.pop();
    s.traverse();

    return 0;
}
