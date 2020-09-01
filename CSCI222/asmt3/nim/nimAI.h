#ifndef NIMAI_H
#define NIMAI_H

using namespace std;

class NimAI
{
public:
    /* Constructs a new Nim AI of a certain skill level
    @param level - the level of the Nim AI, either smart or stupid
    @return nothing
    */

    NimAI(int random);

    /* Gets the computer's move given the number of marbles remaining
    @param marbles - the number of marbles remaining in the game
    @return the number of marbles the Nim AI would like to remove
    */
    int getMove(int marbles);

    //returns the NIM AI object
    string print() const;

private:
    enum skillLevel
    {
        STUPID,
        SMART
    };
    skillLevel skill;
};

#endif