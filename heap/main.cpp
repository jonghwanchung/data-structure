#include <iostream>

#include "heap.h"

using namespace std;

int main(void){
    cout << "Min-Heap : " << endl;

    maxHeap<int> max_heap;

    // push : 11, 3, 2
    max_heap.push(11);
    max_heap.push(3);
    max_heap.push(2);
    max_heap.printAll();

    // pop : 3~
    max_heap.pop();
    max_heap.printAll();

    // push : 15, 5, 4, 45
    max_heap.push(15);
    max_heap.push(5);
    max_heap.push(4);
    max_heap.push(45);
    max_heap.printAll();

    return 0;
}