#include <iostream>
#include <stdlib.h>
#include "nimAI.h"

using namespace std;

NimAI::NimAI(int random)
{
    if (random == 0)
        skill = STUPID;
    else
        skill = SMART;
}

int NimAI::getMove(int marbles)
{
    srand((unsigned)time(NULL));
    if (skill == STUPID)
    {
        if (marbles != 1)
            return rand() % (marbles / 2) + 1;
        return 1;
    }
    else
    {
        if (marbles > 63)
            return marbles - 63;
        else if (marbles > 31)
            return marbles - 31;
        else if (marbles > 15)
            return marbles - 15;
        else if (marbles > 7)
            return marbles - 7;
        else if (marbles > 3)
            return marbles - 3;
        else if (marbles == 1)
            return 1;
        else
            return rand() % (marbles / 2) + 1;
    }
}

string NimAI::print() const
{
    if (skill == STUPID)
        return "The computer's skill level this game is stupid\n";
    else
        return "The computer's skill level this game is smart\n";
}