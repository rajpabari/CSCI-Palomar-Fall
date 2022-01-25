#include "DiskMover.h"
#include <iostream>

// if you want to change any of the parameters, change them here
#define DISKS 3
#define START_PEG 1
#define END_PEG 3

using namespace std;

int main() {
  // makes a DiskMover and uses it to solve tower of Hanoi
  cout << "Tower of Hanoi Solution: " << DISKS << " disks from peg "
       << START_PEG << " to peg " << END_PEG << endl;
  DiskMover mover(DISKS, START_PEG, END_PEG);
  mover.solve();
  return 0;
}