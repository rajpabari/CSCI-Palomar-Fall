#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Segment.h"

using namespace std;

//TODO: dont forget to comment this code

vector<Segment> trackInit(int size, bool isHorizontal)
{
    vector<Segment> returnTrack(size);
    string initType = "-";
    if (!isHorizontal)
        initType = "|";

    for (int i = 0; i < size; i++)
    {
        returnTrack[i].id = i;
        returnTrack[i].state = 0;
        returnTrack[i].type = initType;
        if (i != 0)
            returnTrack[i].prev = &returnTrack[i - 1];
        if (i != 10)
            returnTrack[i].next = &returnTrack[i + 1];

        //cout << returnTrack[i].type;
    }

    return returnTrack;
}

int main()
{
    vector<Segment> topTrack = trackInit(10, true);
    vector<Segment> bottomTrack = trackInit(10, true);
    vector<Segment> leftTrack = trackInit(5, false);

    for (int i = 0; i < topTrack.size(); i++)
    {
        cout << topTrack[i].type;
    }

    return 0;
}