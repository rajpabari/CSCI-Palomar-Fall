#include "DiskMover.h"

string DiskMover::getStackContents(stack<int> toPrint) {
  // NOTE: this is being constructed in top to bottom order, then reversed
  // start with the end bracket
  string ans = "]";

  // add each value from the stack to the answer
  for (stack<int> dump = toPrint; !dump.empty(); dump.pop()) {
    ans += " ,";
    ans += to_string(dump.top());
  }
  // end with the start bracket
  ans += "[";
  // reverse the string and return it
  reverse(ans.begin(), ans.end());
  return ans;
}

void DiskMover::printStates() {
  // print the states of each peg using getStackContents helper
  cout << "Peg 1: " << getStackContents(a) << " Peg 2: " << getStackContents(b)
       << " Peg 3: " << getStackContents(c) << endl;
}

void DiskMover::initStartTower() {
  // to identify which tower should get the initial disks, check the start
  // integer
  switch (start) {
  case 2: {
    // for loop pushes numbers onto the stack
    for (int i = numDisks; i >= 1; i--) {
      b.push(i);
    }
    // want to print the original state of the board to confirm it initialized
    // right
    printStates();
    break;
  }
  case 3: {
    for (int i = numDisks; i >= 1; i--) {
      c.push(i);
    }
    printStates();
    break;
  }
  default:
  case 1: {
    for (int i = numDisks; i >= 1; i--) {
      a.push(i);
    }
    printStates();
  }
  }
}

DiskMover::DiskMover(int disks, int s, int f) {
  // assign paramaters to class variables
  start = s;
  finish = f;
  numDisks = disks;
  // initialize the start tower to set up for hanoi
  initStartTower();
}

void DiskMover::getMoves(stack<int> *source, stack<int> *spare,
                         stack<int> *target, int m) {
  // base case, there's only 1 disk to move
  if (m <= 1) {
    // we should just be moving this from the source peg to the target peg
    //  double check that the source peg isn't empty (we'll get an error)
    if (!source->empty()) {
      target->push(source->top());
      source->pop();
    }
    // we made a move, so print out the move we made
    printStates();
    // stop this recursion because this is the base case
    return;
  }
  // move m-1 disks to the spare rod from the source rod
  getMoves(source, target, spare, m - 1);

  // move disk m from source to target
  target->push(source->top());
  source->pop();
  // we just made a move so print it out
  printStates();

  // move those m-1 disks that we just put from source to spare,
  // and move them from spare to target
  getMoves(spare, source, target, m - 1);
}

void DiskMover::solve() {
  // identify which order to pass the pegs into the solver by checking the start
  // and finish variables
  switch (start) {
    // this is pretty obvious what it's doing
  case 3: {
    switch (finish) {
    case 1: {
      getMoves(&c, &b, &a, numDisks);
      break;
    }
    default:
    case 2: {
      getMoves(&c, &a, &b, numDisks);
    }
    }
    break;
  }
  case 2: {
    switch (finish) {
    case 1: {
      getMoves(&b, &c, &a, numDisks);
      break;
    }
    default:
    case 3: {
      getMoves(&b, &a, &c, numDisks);
    }
    }
    break;
  }
  default:
  case 1: {
    switch (finish) {
    case 2: {
      getMoves(&a, &c, &b, numDisks);
      break;
    }
    default:
    case 3: {
      getMoves(&a, &b, &c, numDisks);
    }
    }
    break;
  }
  }
}
