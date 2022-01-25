#ifndef COMBOLOCK_H
#define COMBOLOCK_H
#include <iostream>

using namespace std;

class ComboLock {
public:
  // Constructor for ComboLock object
  // @param secret1 the first secret code number
  // @param secret2 the second secret code number
  // @param secret3 the third secret code number
  ComboLock(int secret1, int secret2, int secret3);

  // resets everything, the equivalent of spinning the lock around a few times
  void reset();

  // Turns the lock dial left a given amount
  // @param ticks the amount to turn the combination lock left by
  // Precondition: ticks >= 0
  void turnLeft(int ticks);

  // Turns the lock dial right a given amount
  // @param ticks the amount to turn the combination lock right by
  // Precondition: ticks >= 0
  void turnRight(int ticks);

  // Says if the lock is able to be opened or not
  // @return true if it can be opened, false if not
  bool open() const;

private:
  int code[3]; // stores the secred numbers
  // true if they got the number correct, false if not
  bool firstCorrect;
  bool secondCorrect;
  bool thirdCorrect;

  // current position of the dial
  int currentPos;
};

#endif