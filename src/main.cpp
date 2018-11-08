#include <iostream>
#include "priority_queue.h"
using namespace std;


int main(){
  //TODO

  PriorityQueue<string> foo(true);
  foo.enqueue("priority 10", 10);
  foo.enqueue("priority 1", 1);
  foo.enqueue("priority 9", 9);
  foo.enqueue("priority 2", 2);
  foo.enqueue("priority 8", 8);
  foo.enqueue("priority 3", 3);
  foo.enqueue("priority 7", 7);
  foo.enqueue("priority 4", 4);
  foo.enqueue("priority 6", 6);
  foo.enqueue("priority 5", 5);

  cout << foo.dequeue() << endl;
  cout << foo.dequeue() << endl;
  cout << foo.dequeue() << endl;

  
  return 0;
}