#ifndef SEGMENT_H
#define SEGMENT_H

#include <string>

using namespace std;

struct Segment {
  int id; // id is primarily for debugging purposes
  int state;
  /*STATE: 1 = train going clockwise
    -1 = train going counterclockwise
    0 = no train*/

  Segment *next;    // pointer for next segment on same track
  Segment *prev;    // pointer for prev segment on same track
  Segment *nextAdj; // pointer for next segment on other track
  Segment *prevAdj; // pointer for prev segment on other track

  bool doneForTurn; // whether the segment processing is done for the round or
                    // not
};

#endif