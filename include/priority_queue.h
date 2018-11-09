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
  //constructors
  PriorityQueue() : min(false), elements(new Cell<T>[capacity]) {};

  PriorityQueue(bool minimum_first) : min(minimum_first), elements(new Cell<T>[capacity]) {};

  PriorityQueue(const PriorityQueue<T> &p) : sz(p.sz), capacity(p.capacity), min(p.min), elements(new Cell<T>[capacity]) {
    elements = new Cell<T>[capacity];
    for (int i = 0; i < p.sz; i++) {
      elements[i] = p.elements[i];
    }
  }

  //overloaded assignment
  PriorityQueue<T> &operator=(const PriorityQueue<T> &p) {
    auto *newElements = new Cell<T>[p.capacity];
    for (int i = 0; i < p.sz; i++) {
      newElements[i] = p.elements[i];
    }

    delete[] elements;
    elements = newElements;
    sz = p.sz;
    capacity = p.capacity;

    return *this;
  }

  //returns if queue is full
  bool full() const{
    return sz == capacity;
  }

  //returns if
  bool empty() const{
    return sz == 0;
  }

  //returns the size
  int size() {
    return sz;
  }


  void enqueue(T e, int priority) {
    if (full()) {
      auto *newElements = new Cell<T>[capacity * 2];
      for (int i = 0; i < sz; i++) {
        newElements[i] = elements[i];
      }
      delete[] elements;
      elements = newElements;
      capacity *= 2;
    }

    elements[sz].info = e;
    elements[sz].priority = priority;
    sortByHeap();
    sz++;
  }

  T dequeue() {
    if (empty()) {
      throw std::runtime_error("Array is empty.");
    }
    T temp = elements[sz-1].info;
    --sz;
    return temp;
  };

  T peek() const{
    if (empty()) {
      throw std::runtime_error("Array is empty.");
    }
    return elements[sz - 1].info;
  }

  ~PriorityQueue() {
    delete[] elements;
  };

protected:
  bool min;
  int capacity = 8;
  int sz = 0;
  Cell<T> *elements;

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

  void sortByHeap() {
    for (int i = (sz + 1) / 2 - 1; i >= 0; i--)
      heapify((sz + 1), i);
    for (int i = sz; i >= 0; i--) {
      swap(0, i);
      heapify(i, 0);
    }
  }

  void heapify(int n, int i) {
    int left = 2 * i + 1;
    int right = left + 1;
    int biggest = i;

    //determine what is less than and what is greater than
    if (min) {
      if (left < n && elements[left].priority < elements[biggest].priority) {
        biggest = left;
      }
      if (right < n && elements[right].priority < elements[biggest].priority) {
        biggest = right;
      }
    } else {
      if (left < n && elements[left].priority > elements[biggest].priority) {
        biggest = left;
      }
      if (right < n && elements[right].priority > elements[biggest].priority) {
        biggest = right;
      }
    }

    //
    if (biggest != i) {
      swap(i, biggest);
      heapify(n, biggest);
    }
  }

};
#endif