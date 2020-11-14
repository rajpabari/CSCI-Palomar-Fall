#ifndef DISKMOVER_H
#define DISKMOVER_H
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class DiskMover {
public:
  // Constructs a new DiskMover
  //@param disks the number of disks to put on starting peg
  //@param s the starting peg (1, 2, or 3)
  //@param f the ending peg (1, 2, or 3)
  // Precondition: s != f
  DiskMover(int disks, int s, int f);

  // Solves that Tower of Hanoi setup
  void solve();

private:
  // each stack represents a tower peg
  // a --> peg 1, b --> peg 2, c --> peg 3
  stack<int> a;
  stack<int> b;
  stack<int> c;

  // stores the variables passed into the constructor
  int numDisks;
  int start;
  int finish;

  // intializes the tower by putting "numDisks" disks onto peg "start"
  void initStartTower();

  // Recursive method that is used internally to solve Hanoi
  // this method moves m disks from source to target peg
  //@param source the origin peg to move from
  //@param spare the peg that's not the target or source peg
  //@param target the peg to move the disks to
  //@param m the number of disks that need to be moved
  void getMoves(stack<int> *source, stack<int> *spare, stack<int> *target,
                int m);

  // Helper method for printStates method
  // Given a stack, output a string with stack contents from bottom to top
  // ie. a stack with contents stack.push(3); stack.push(2); stack.push(1);
  // should get returned as [3, 2, 1, ]
  // @param toPrint the stack to get the string from
  // @return the formatted output string
  string getStackContents(stack<int> toPrint);

  // prints which disks are on each peg 1, 2, and 3
  void printStates();
};
#endif