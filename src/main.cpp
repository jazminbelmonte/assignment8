#include <iostream>
#include "priority_queue.h"
using namespace std;


int main(){

  /* test run

  PriorityQueue<string> foo(false);
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

  cout << foo.dequeue() <<endl;

  */


  PriorityQueue<string> foo(true);
  foo.enqueue("The Grinch", 10);
  foo.enqueue("Mayor Of Who-ville", 1);
  foo.enqueue("Horton", 9);
  foo.enqueue("Thing 1", 2);
  foo.enqueue("Fish", 8);
  foo.enqueue("King Looie Katz", 3);
  foo.enqueue("Wocket", 7);
  foo.enqueue("Sneetches", 4);
  foo.enqueue("Cat in the Hat", 6);
  foo.enqueue("Lorax", 5);

  cout << foo.dequeue() << endl;



  return 0;
}