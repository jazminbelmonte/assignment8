#include <iostream>
#include "priority_queue.h"
using namespace std;


int main(){

  /* test run

  PriorityQueue<string> q(false);
  q.enqueue("priority 10", 10);
  q.enqueue("priority 1", 1);
  q.enqueue("priority 9", 9);
  q.enqueue("priority 2", 2);
  q.enqueue("priority 8", 8);
  q.enqueue("priority 3", 3);
  q.enqueue("priority 7", 7);
  q.enqueue("priority 4", 4);
  q.enqueue("priority 6", 6);
  q.enqueue("priority 5", 5);

  cout << q.dequeue() <<endl;

  */


  PriorityQueue<string> q(true);
  q.enqueue("The Grinch", 10);
  q.enqueue("Mayor Of Who-ville", 1);
  q.enqueue("Horton", 9);
  q.enqueue("Thing 1", 2);
  q.enqueue("Fish", 8);
  q.enqueue("King Looie Katz", 3);
  q.enqueue("Wocket", 7);
  q.enqueue("Sneetches", 4);
  q.enqueue("Cat in the Hat", 6);
  q.enqueue("Lorax", 5);

  cout << q.dequeue() << endl;



  return 0;
}