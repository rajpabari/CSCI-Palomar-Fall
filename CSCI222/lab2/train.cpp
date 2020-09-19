#include <iostream>
#include <vector>

using namespace std;

//TODO: dont forget to comment this code

struct Segment
{
    int state;
    Segment *next;
    Segment *prev;
};

int main()
{
    vector<Segment> track;
    Segment temp;
    temp.state = 0;
    temp.next = NULL;
    temp.prev = NULL;
    track.push_back(temp);

    for (int i = 1; i < 10; i++)
    {
        temp.prev = &track[i - 1];
        track.push_back(temp);
    }

    return 0;
}