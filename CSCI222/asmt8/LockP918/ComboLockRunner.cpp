#include "ComboLock.h"
#include <iostream>

using namespace std;

int main() {

  // simple test, this should be open
  ComboLock lock1(30, 10, 25);
  lock1.turnRight(30);
  lock1.turnLeft(20);
  lock1.turnRight(15);
  if (lock1.open())
    cout << "Lock 1 is open" << endl;
  else
    cout << "Lock 1 is not open" << endl;

  ComboLock lock2(30, 10, 25);
  lock2.turnRight(70); // turn all the way right once, then 30
  lock2.turnLeft(100); // turn fully left twice, then 20 more left from 30
  lock2.turnRight(10); // turn 10 more right from 10 to be at 20

  // it should NOT be open because the last needs to be at 25 not 20
  if (lock2.open())
    cout << "Lock 2 is open" << endl;
  else
    cout << "Lock 2 is not open" << endl;

  // turn it 5 more right to get to 25
  lock2.turnRight(5);

  // it should be open
  if (lock2.open())
    cout << "Lock 2 is open" << endl;
  else
    cout << "Lock 2 is not open" << endl;

  ComboLock lock3(30, 10, 25);
  lock3.turnLeft(5);   // turn 5 left
  lock3.turnRight(35); // then 35 right from 5 left to get 30
  lock3.turnRight(10); // 10 right from 35 is 5
  lock3.turnLeft(30);  // left 30 from 5 is 10
  lock3.turnRight(15); // right 15 from 10 is 25
  // this should be opened now because it did all parts correctly
  if (lock3.open())
    cout << "Lock 3 is open" << endl;
  else
    cout << "Lock 3 is not open" << endl;

  return 0;
}