#ifndef _MAX_HEAP_H_
#define _MAX_HEAP_H_

#include <vector>

using namespace std;

template <typename T>
class maxHeap{
public:
    /* constructor */
    maxHeap();

public:
    /* basic methods */
    void push(T key);
    void pop();
    int top();

public:
    /* custom method */
    void printAll();

private:
    /* internal methods */
    void maxHeaptifyBU();   // for push()
    void maxHeaptifyTD();   // for pop()

private:
    vector<T> _elements;    /* data */

};  // class maxHeap

#endif  /* _MAX_HEAP_H_ */