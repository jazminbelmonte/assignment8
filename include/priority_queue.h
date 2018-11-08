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
  //constructors                                //???
  PriorityQueue(): sz(0), capacity(8), elements(new Cell<T>[capacity]){}
  PriorityQueue(bool min): min(false), sz(0), capacity(8), elements(new Cell<T>[capacity]){}

  //copy constructor
  PriorityQueue(const PriorityQueue<T>& p): sz(p.sz), capacity(p.capacity) {
    elements = new T[capacity];
    for(int i = 0; i < p.sz; i++){
      elements[i] = p.elements[i];
    }
  }

  //overloaded assignment operator
  PriorityQueue<T>& operator=(const PriorityQueue<T>& c){
    T* newElements = new T[c.capacity];
    for(int i = 0; i < sz; i++){
      newElements[i] = c.elements[i];
    }

    delete[] elements;
    elements = newElements;
    sz = c.sz;
    capacity = c.capacity;

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
    Cell<T> newCell = new Cell<T>(e);
    newCell.priority = p;
    if (sz == capacity) {
      T *newElements = new T[capacity * 2];
      for (int i = 0; i < sz; i++) {
        newElements[i] = elements[i];
      }
      delete[] elements;
      elements = newElements;
      capacity *= 2;
    }
    elements[newCell.priority] = e;
    sz++;
    heapify(e, sz, min);
  }

  //TODO
  //removes and returns value of the element with the max/min if queue is max/min
  //which will be the first element
  T dequeue(){
    if(empty()){
      throw std::runtime_error("Queue is empty");
    }

    auto temp = elements[0];
    delete elements[0];
    return temp;
  }

  //TODO
  //returns the value of the elements with the max/min if the queue is max/min
  //which will be the first element
  T peek() const{
    if(empty()){
      throw std::runtime_error("Queue is empty");
    }
    return elements[0];
  }

  void buildHeap(bool reversed) {
    for (int i = sz / 2 - 1; i >= 0; i--) {
      heapify(i, sz, reversed);
    }
  }

  void heapify(int p, int hsz, bool min) {
    int left = 2 * p + 1;
    int right = left + 1;
    int largest = p;
    if (left < hsz && lessOrGreaterThan(p, left, min)) {
      largest = left;
    }

    if (right < hsz && lessOrGreaterThan(largest, right, min)) {
      largest = right;
    }

    if (largest != p) {
      swap(p, largest);
      heapify(largest, hsz, min);
    }
  }

  //destructor
  ~PriorityQueue(){
    delete[] elements;
  }
protected:
  unsigned sz, capacity;
  bool min;
  Cell<T>* elements;


  void swap(T a, T b){
    auto tmp = elements[a];
    elements[a] = elements[b];
    elements[b] = tmp;
  }

  bool lessOrGreaterThan(int a, int b, bool min){
    return (!min && elements[a] < elements[b]) || (min && elements[a] > elements[b]);
  }
};
#endif