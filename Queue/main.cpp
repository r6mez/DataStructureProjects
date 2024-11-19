#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue<int> q;
    q.enqueue(5);
    q.traverse();
    q.enqueue(10);
    q.traverse();
    q.dequeue();
    q.traverse();
    q.enqueue(12);
    q.traverse();
    q.dequeue();
    q.traverse();
    q.enqueue(3);
    q.traverse();
    return 0;
}
