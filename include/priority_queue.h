#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <iostream>
#include <stdexcept>
#include <cmath>

template<typename T>
struct Cell {
  T info;
  int priority = 0;
};

template<typename T>
class PriorityQueue {
public:
  //constructors                                                 //???
  PriorityQueue(): min(false), sz(0), capacity(8), elements(new Cell<T>[capacity]){};

  PriorityQueue(bool min): min(min), sz(0), capacity(8), elements(new Cell<T>[capacity]){};

  //copy constructor
  PriorityQueue(const PriorityQueue<T>& p): sz(p.sz), capacity(p.capacity), min(p.min) {
    elements = new Cell<T>[capacity];
    for(int i = 0; i < p.sz; i++){
      elements[i] = p.elements[i];
    }
  }

  //overloaded assignment operator
  PriorityQueue<T>& operator=(const PriorityQueue<T>& p){
    Cell<T>* newElements = new Cell<T>[p.capacity];
    for(int i = 0; i < p.sz; i++){
      newElements[i] = p.elements[i];
    }

    delete[] elements;
    elements = newElements;
    sz = p.sz;
    capacity = p.capacity;

    return *this;
  }

  //returns whether queue is full
  bool full() const {
    return sz == capacity;
  }

  //returns whether queue is full
  bool empty() const {
    return sz == 0;
  }

  //returns size
  int size() const {
    return sz;
  }

  //TODO
  //adds element e with priority p into the queue
  //if the array is full then double the size of the array
  void enqueue(T e, int p, bool min = false) {
    //if empty
    if (sz == capacity) {
      auto *newElements = new Cell<T>[capacity * 2];
      for (int i = 0; i < sz; i++) {
        newElements[i] = elements[i];
      }
      delete[] elements;
      elements = newElements;
      capacity *= 2;
    }

    elements[sz].info = e;
    elements[sz].priority = p;

    buildHeap();
    sz++;
    /*Cell<T> newCell;
    newCell.info = e;
    newCell.priority = p;
    elements[sz] = newCell;
    sz++;
    buildHeap(min);*/
  }

  //TODO
  //removes and returns value of the element with the max/min if queue is max/min
  //which will be the first element
  T dequeue(){
    if(empty()){
      throw std::runtime_error("Priority Queue is empty");
    }

    T temp = elements[sz-1].info;
    sz--;
    buildHeap();
    return temp;
  }

  //TODO
  //returns the value of the elements with the max/min if the queue is max/min
  //which will be the first element
  T peek() const{
    if(empty()){
      throw std::runtime_error("Queue is empty");
    }
    return elements[sz-1].info;
  }

  //destructor
  ~PriorityQueue(){
    delete[] elements;
  }
protected:
  unsigned int sz, capacity;
  bool min;
  Cell<T>* elements;

  void buildHeap() {
    int size = sz +1;
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(elements, size, i);
    }
    for (int i = sz; i >= 0; i--){
      swap(0, i);
      heapify(elements, i, 0);
    }
  }

  void heapify(Cell<T> cellArray[], int p, int i) {
    int left = 2 * p + 1;
    int right = left + 1;
    int largest = p;

    if (min) {
      if (left < p && cellArray[left].priority < cellArray[largest].priority){
        largest = left;
      } else if (right < i && cellArray[right].priority < cellArray[largest].priority){
        largest = right;
      }
    } else {
      if (left < p && cellArray[left].priority > cellArray[largest].priority){
        largest = left;
      } else if (right < p && cellArray[right].priority > cellArray[largest].priority){
        largest = right;
      }
    }

    if (largest != p) {
      swap(i, largest);
      heapify(cellArray, p, largest);
    }
  }

  void swap(int a, int b){
    Cell<T> temporary;
    //copying a into temp
    temporary.info = elements[a].info;
    temporary.priority = elements[a].priority;
    //copying b into a
    elements[a].info = elements[b].info;
    elements[a].priority = elements[b].priority;
    //copying from temp (a) into b
    elements[b].info = temporary.info;
    elements[b].priority = temporary.priority;
  }

  /*bool lessOrGreaterThan(T a, T b, bool min){
    return (!min && elements[a] < elements[b]) || (min && elements[a] > elements[b]);
  }*/
};
#endif