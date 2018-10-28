#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "priority_queue.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

TEST_CASE("Test maximum-first") {
  PriorityQueue<char> q;
  q.enqueue('p', 'p');
  q.enqueue('r', 'r');
  q.enqueue('i', 'i');
  q.enqueue('o', 'o');
  q.enqueue('r', 'r');
  q.enqueue('i', 'i');
  q.enqueue('t', 't');
  q.enqueue('y', 'y');
  CHECK(q.full());
  q.enqueue('q', 'q');
  q.enqueue('u', 'u');
  q.enqueue('e', 'e');
  q.enqueue('u', 'u');
  q.enqueue('e', 'e');

  PriorityQueue<char> a(q), b(q);
  CHECK(a.size() == 13);
  a.enqueue('s', 's');
  CHECK(a.size() == 14);
  CHECK(a.dequeue() == 'y');
  CHECK(a.dequeue() == 'u');
  CHECK(a.dequeue() == 'u');
  CHECK(a.dequeue() == 't');
  CHECK(a.dequeue() == 's');
  CHECK(a.size() == 9);
  b = a;

  a.enqueue('x', 'x');
  CHECK(a.peek() == 'x');
  a.enqueue('w', 'w');
  CHECK(a.peek() == 'x');
  a.enqueue('y', 'y');
  a.dequeue();
  CHECK(a.peek() == 'x');

  b.dequeue();
  b.dequeue();
  b.dequeue();
  b.dequeue();
  b.dequeue();
  b.dequeue();
  b.dequeue();
  b.dequeue();
  CHECK(b.dequeue() == 'e');
  CHECK(b.empty());
  CHECK_THROWS(b.peek());
  CHECK_THROWS(b.dequeue());
}

TEST_CASE("Test minimum-first") {
  PriorityQueue<char> q(true);
  q.enqueue('p', 'p');
  q.enqueue('r', 'r');
  q.enqueue('i', 'i');
  q.enqueue('o', 'o');
  q.enqueue('r', 'r');
  q.enqueue('i', 'i');
  q.enqueue('t', 't');
  q.enqueue('y', 'y');
  CHECK(q.full());
  q.enqueue('q', 'q');
  q.enqueue('u', 'u');
  q.enqueue('e', 'e');
  q.enqueue('u', 'u');
  q.enqueue('e', 'e');

  PriorityQueue<char> a(q), b(q);
  CHECK(a.size() == 13);
  a.enqueue('s', 's');
  CHECK(a.size() == 14);
  CHECK(a.dequeue() == 'e');
  CHECK(a.dequeue() == 'e');
  CHECK(a.dequeue() == 'i');
  CHECK(a.dequeue() == 'i');
  CHECK(a.dequeue() == 'o');
  CHECK(a.size() == 9);
  b = a;

  a.enqueue('x', 'x');
  CHECK(a.peek() == 'p');
  a.enqueue('o', 'o');
  CHECK(a.peek() == 'o');
  a.enqueue('q', 'q');
  a.dequeue();
  CHECK(a.peek() == 'p');

  b.dequeue();
  b.dequeue();
  b.dequeue();
  b.dequeue();
  b.dequeue();
  b.dequeue();
  b.dequeue();
  b.dequeue();
  CHECK(b.dequeue() == 'y');
  CHECK(b.empty());
  CHECK_THROWS(b.peek());
  CHECK_THROWS(b.dequeue());
}