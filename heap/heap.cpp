#include <vector>
#include <cmath>    // log
#include <iostream>

#include "heap.h"

using namespace std;

/* constructor */
template <typename T>
maxHeap<T>::maxHeap(){    
}


/* basic methods */
template <typename T>
void maxHeap<T>::push(T key){
    _elements.push_back(key);
    maxHeaptifyBU();  // heapify (bottom-up)
}

template <typename T>
void maxHeap<T>::pop(){
    if(_elements.empty()){
        return ;
    }

    int last = _elements.size() - 1;
    _elements[0] = _elements[last];
    _elements.erase(_elements.begin() + last);   // maximum

    maxHeaptifyTD();  // heapify (top-down)
}

template <typename T>
int maxHeap<T>::top(){
    if(!_elements.empty()){
        return _elements[0]; 
    }
    return -1;
}


/* custom method */
template <typename T>
void maxHeap<T>::printAll(){
    for(int i = 0; i < _elements.size(); i++){
        cout << _elements[i] << ", ";
    }
    cout << endl;
}


/* internal methods */
template <typename T>
void maxHeap<T>::maxHeaptifyBU(){
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

template <typename T>
void maxHeap<T>::maxHeaptifyTD(){
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