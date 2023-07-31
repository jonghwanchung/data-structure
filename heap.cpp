#include <vector>
#include <cmath>    // log
#include <iostream>

using namespace std;

template <class T>
class maxHeap{
public:
    maxHeap(){}

public:
    void push(T key){
        _elements.push_back(key);
        maxHeaptifyBU();  // heapify (bottom-up)
    }

    void pop(){
        if(_elements.empty()){
            return ;
        }

        int last = _elements.size() - 1;
        _elements[0] = _elements[last];
        _elements.erase(_elements.begin() + last);   // maximum

        maxHeaptifyTD();  // heapify (top-down)
    }

    int top(){
        if(!_elements.empty()){
            return _elements[0]; 
        }
        return -1;
    }

public:
    void printAll(){
        for(int i = 0; i < _elements.size(); i++){
            cout << _elements[i] << ", ";
        }
        cout << endl;
    }

private:
    void maxHeaptifyBU(){
        int current = _elements.size() - 1;  // last
        while(current > 0){
            int parent = (current + 1) / 2 - 1;
            if(parent >= _elements.size()){
                break;
            }
            
            if(_elements[parent] >= _elements[current]){
                break;
            }

            swap(_elements[parent], _elements[current]);
            current = parent;
        }
    }

    void maxHeaptifyTD(){
        int current = 0;
        while(current < _elements.size()){
            int left = ((current + 1) * 2) - 1;
            int right = (current + 1) * 2;

            int largest = current;
            if(left < _elements.size() && _elements[left] > _elements[current]){
                largest = left;
            }

            if(right < _elements.size() && _elements[right] > _elements[current]){
                largest = right;
            }

            if(largest == current){
                break;
            }

            swap(_elements[largest], _elements[current]);
            current = largest;
        }
    }

private:
    vector<T> _elements;    /* data */

};  // class maxHeap

int main(void){
    cout << "Min-Heap : " << endl;

    maxHeap<int> max_heap;

    // push : 11, 3, 2
    max_heap.push(11);
    max_heap.push(3);
    max_heap.push(2);
    max_heap.printAll();

    // pop : 3
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