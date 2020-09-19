#ifndef SEGMENT_H
#define SEGMENT_H

using namespace std;

struct Segment
{
    int id;
    int state;
    Segment *next;
    Segment *prev;
    string type;
};

#endif