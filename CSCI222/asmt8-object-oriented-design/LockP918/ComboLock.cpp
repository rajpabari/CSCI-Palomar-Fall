#include "ComboLock.h"

void ComboLock::reset() {
  // resetting so nothing is correct and it starts back at 0
  firstCorrect = secondCorrect = thirdCorrect = false;
  currentPos = 0;
}

ComboLock::ComboLock(int secret1, int secret2, int secret3) {

  // initialize secret code values to private member variables
  code[0] = secret1;
  code[1] = secret2;
  code[2] = secret3;

  // initialize booleans and currentPos
  reset();
}

void ComboLock::turnLeft(int ticks) {
  // subtract the ticks from the position to move it left
  currentPos -= ticks;

  // can't have a negative position, so add 40 to it if it is negative
  // ie. if currentPos == -1 it's really supposed to be at position 39
  while (currentPos < 0)
    currentPos += 40;
  // if the first one is correct, it's time for this one to possibly be correct
  // so also check if it's at the right position for the one where you're
  // supposed to turn left
  // if it is, then the person got the second secret number correct
  if (firstCorrect && currentPos == code[1])
    secondCorrect = true;
}

void ComboLock::turnRight(int ticks) {
  // add the ticks from the position to move it right
  currentPos += ticks;

  // take it mod 40 to ensure it's in the range 0-39
  // ie. if currentPos == 40, it's really supposed to be at 0
  currentPos %= 40;

  // if it's time to guess the first value, and they're at the right position
  // they got the first secret number correct
  if (!firstCorrect && currentPos == code[0]) {
    firstCorrect = true;
  }
  // if it's time to guess the third value, and they're at the right position
  // they got the third secret number correct
  else if (secondCorrect && currentPos == code[2]) {
    thirdCorrect = true;
  }
}
bool ComboLock::open() const {
  // if they have all of the numbers correct, return true
  // otherwise, return false
  return firstCorrect && secondCorrect && thirdCorrect;
}
