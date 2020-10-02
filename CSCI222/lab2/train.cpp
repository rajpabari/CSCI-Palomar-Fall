#include "Segment.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <vector>

// NOTE: in the test case screenshot, round 6 to 7 to 8 shows
// the trains switching pretty well

using namespace std;

#define TRACK_SIZE 10 // number of segments in track
#define TRAINS 4      // number of trains
#define TRACKS 2      // number of tracks (1 inner, 1 outer)
#define SIMS 10       // number of runs

// Initializes a track as an array of segments
// @param Segment seg[TRACK_SIZE] a segment array to initialize
// @param int parity, -1 if inner track and 1 if outer track (to set ID)
// @return none
void trackInit(Segment seg[TRACK_SIZE], int parity) {
  // randomly set the location of the two trains on the track
  int trainLoc1 = rand() % 10;
  int trainLoc2 = rand() % 10;

  // if the same location was chosen for both (they're equal)
  while (trainLoc1 == trainLoc2) {
    // randomly generate a new 2nd location until they're distinct
    trainLoc2 = rand() % 10;
  }

  // intial state of the train (1 = clockwise, -1 = counter clock wise)
  int trainState;

  for (int i = 0; i < TRACK_SIZE; i++) {
    // set distinct id for debugging purposes
    seg[i].id = (i * parity) + parity;

    // initalize bool doneForTurn
    seg[i].doneForTurn = false;

    // set the state to 0 (no train) by default
    seg[i].state = 0;

    // if we need to put a train here
    if (i == trainLoc1 || i == trainLoc2) {
      // decide the direction of the train by picking a random number between
      // 0 and 1
      trainState = rand() % 2;

      // valid states for seg w/ train are -1 or 1, so if it's 0, subtract 1
      if (trainState == 0)
        trainState--;

      // set the state to have a train in random direction
      seg[i].state = trainState;
    }
    // if i isn't 0, previous is just previous index in array
    if (i != 0)
      seg[i].prev = &seg[i - 1];
    // if i is 0, previous is the last segment in array
    else {
      seg[i].prev = &seg[TRACK_SIZE - 1];
    }

    // if i isn't at end of array, next is next index in array
    if (i != TRACK_SIZE - 1)
      seg[i].next = &seg[i + 1];

    // if i is at end of array, next is segment at beginning of array
    else {
      seg[i].next = &seg[0];
    }
  }
}

// Initializes the pointers to adjacent tracks
// @param Segment outer[TRACK_SIZE] the outer track, an array of Segments
// @param Segment inner[TRACK_SIZE] the inner track, an array of Segments
// @return none
void adjInit(Segment outer[TRACK_SIZE], Segment inner[TRACK_SIZE]) {

  for (int i = 0; i < TRACK_SIZE; i++) {

    // if i isn't 0, previous is just previous index in adjacent array
    if (i != 0) {
      outer[i].prevAdj = &inner[i - 1];
      inner[i].prevAdj = &outer[i - 1];
    }
    // if i is 0, previous is last index in adjacent array
    else {
      outer[i].prevAdj = &inner[TRACK_SIZE - 1];
      inner[i].prevAdj = &outer[TRACK_SIZE - 1];
    }

    // if i isn't at end of array, next is next index in adjacent array
    if (i != TRACK_SIZE - 1) {
      outer[i].nextAdj = &inner[i + 1];
      inner[i].nextAdj = &outer[i + 1];
    }

    // if i is at end of array, next is first index in adjacent array
    else {
      outer[i].nextAdj = &inner[0];
      inner[i].nextAdj = &outer[0];
    }
  }
}

// Get a string representation of a segment for printing
// @param int state the state of the segment (0=none,1=CW,-1=CCW)
// @param int parity 1 if on upper track, -1 if on bottom track
string getString(int state, int parity) {

  // if it's CCW on upper track or CW on bottom
  if (state * parity == -1) {
    return " -<- ";
  }
  // if it's CW on bottom track or CCW on upper
  else if (state * parity == 1) {
    return " ->- ";
  }
  // if there's no train
  else {
    return " --- ";
  }
}

// Output formatted string representation of the track using cout
// @param Segment outer[TRACK_SIZE] the outer track, an array of Segments
// @param Segment inner[TRACK_SIZE] the inner track, an array of Segments
// @return none
void printTrack(Segment outer[TRACK_SIZE], Segment inner[TRACK_SIZE]) {

  // print upper outer track
  cout << "+";
  for (int i = 0; i < TRACK_SIZE / 2; i++) {
    cout << getString(outer[i].state, 1);
    continue;
  }
  cout << "+" << endl;

  // print first row of Xs
  cout << "|  X    X    X    X    X  |" << endl;

  // print upper inner track
  cout << "|";
  for (int i = 0; i < TRACK_SIZE / 2; i++) {
    cout << getString(inner[i].state, 1);
  }
  cout << "|" << endl;

  // print middle vertical lines
  cout << "| |                     | |" << endl;

  // print lower inner track
  cout << "|";

  // note: needs to go backwards through array in order to preserve
  // the integrity of next and prev. otherwise, trains would
  // hop from top right corner to bottom left
  for (int i = TRACK_SIZE - 1; i >= TRACK_SIZE / 2; i--) {
    cout << getString(inner[i].state, -1);
  }
  cout << "|" << endl;

  // print bottom row of Xs
  cout << "|  X    X    X    X    X  |" << endl;

  // print lower outer track
  cout << "+";

  // same note as above applies
  for (int i = TRACK_SIZE - 1; i >= TRACK_SIZE / 2; i--) {
    cout << getString(outer[i].state, -1);
    continue;
  }
  cout << "+" << endl;
  cout << "\n";
}

// Moves a train clockwise
// @param Segment *seg a segment with a train on it that needs to be moved CW
// @return none
void moveCW(Segment *seg) {
  // set state of next segment to be CW, train still going CW
  seg->next->state = 1;

  // set state of current segment to be 0 because train has left
  seg->state = 0;

  // neither of these segments has a train that needs to be
  // moved again this turn
  seg->doneForTurn = true;
  seg->next->doneForTurn = true;
}

// Moves a train counterclockwise
// @param Segment *seg a segment with a train on it that needs to be moved CCW
// @return none
void moveCCW(Segment *seg) {
  // set state of last segment to be CCW bc train still going CCW
  seg->prev->state = -1;

  // set state of current segment to be 0 because train has left
  seg->state = 0;

  // neither of these segments has a train that needs to be
  // moved again this turn
  seg->doneForTurn = true;
  seg->prev->doneForTurn = true;
}

// Moves a train counterclockwise to adjacent track
// @param Segment *seg a segment with a train that needs to be moved like that
// @return none
void moveCCWAdj(Segment *seg) {
  // set state of last segment in adjacent track to be CCW bc train going CCW
  seg->prevAdj->state = -1;

  // set state of current segment to be 0 because train has left
  seg->state = 0;

  // neither of these segments has a train that needs to be
  // moved again this turn
  seg->doneForTurn = true;
  seg->prevAdj->doneForTurn = true;
}

// Moves a train clockwise to adjacent track
// @param Segment *seg a segment with a train that needs to be moved like that
// @return none
void moveCWAdj(Segment *seg) {
  // set state of next segment in adjacent track to be CW bc train going CW
  seg->nextAdj->state = 1;

  // set state of current segment to be 0 because train has left
  seg->state = 0;

  // neither of these segments has a train that needs to be
  // moved again this turn
  seg->doneForTurn = true;
  seg->nextAdj->doneForTurn = true;
}

// Calls mover functions when they are appropriate
// @param Segment *seg pointer to segment that may or may not need to be moved
// @return none
void doMove(Segment *seg) {

  // if it's already been moved or there's no train
  if (seg->doneForTurn || seg->state == 0) {
    // mark it as done for the turn
    seg->doneForTurn = true;
  }
  // if there's a train trying to go CW
  else if (seg->state == 1) {

    // if it can go CW in the same track, do that
    if (seg->next->state == 0) {
      moveCW(seg);
    }
    // if it can go CW in the adjacent track, do that
    else if (seg->nextAdj->state == 0) {
      moveCWAdj(seg);
    }

    // if it can do neither, doneForTurn would still be false
    // so the segment will be revisited
  }
  // if there is a train trying to go CCW
  else {
    // if it can go CCW in the same track, do that
    if (seg->prev->state == 0) {
      moveCCW(seg);
    }
    // if it can go CCW in the adjacent track, do that
    else if (seg->prevAdj->state == 0) {
      moveCCWAdj(seg);
    }
    // if it can do neither, doneForTurn would still be false
    // so the segment will be revisited
  }
}

// Move the trains for one round using helper methods above
// @param Segment outer[TRACK_SIZE] the outer track, an array of Segments
// @param Segment inner[TRACK_SIZE] the inner track, an array of Segments
// @return none
void moveTrains(Segment outer[TRACK_SIZE], Segment inner[TRACK_SIZE]) {

  // begin by setting doneForTurn as false
  // so that every segment is checked
  for (int i = 0; i < TRACK_SIZE; i++) {
    outer[i].doneForTurn = false;
    inner[i].doneForTurn = false;
  }

  // run this as many times as there are trains
  // worst case scenario is ->- ->- ->- ->- (number of trains)
  // this would require 4 runs to get it right, thats why
  // its number of trains for the number of loops
  for (int times = 0; times < TRAINS; times++) {

    for (int i = 0; i < TRACK_SIZE; i++) {

      // try to move each outer and inner segment
      doMove(&outer[i]);
      doMove(&inner[i]);
    }
  }
}

// Execute the program
int main() {

  // set random seed
  srand(time(0));

  // initialize track arrays of Segments in memory
  Segment outerTrack[TRACK_SIZE];
  Segment innerTrack[TRACK_SIZE];

  for (int i = 0; i < TRACK_SIZE; i++) {
    outerTrack[i] = *(new Segment);
    innerTrack[i] = *(new Segment);
  }

  // call init functions to initialize them with actual values
  trackInit(outerTrack, 1);
  trackInit(innerTrack, -1);
  adjInit(outerTrack, innerTrack);

  // do the actual simulation SIMS times
  for (int i = 0; i < SIMS; i++) {

    // print round number and track representation
    cout << "ROUND " << i << endl;
    printTrack(outerTrack, innerTrack);

    // move the trains
    moveTrains(outerTrack, innerTrack);
  }

  // print the last round and last state of track
  cout << "ROUND " << SIMS << endl;
  printTrack(outerTrack, innerTrack);

  return 0;
}