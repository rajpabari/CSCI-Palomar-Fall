#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "nimAI.h"

using namespace std;

int main()
{
    srand((unsigned)time(NULL)); //start random at unique point
    NimAI computer(rand() % 2);  //initialize NimAI object
    cout << computer.print();    //alert user of the computer's skill level

    int marbles = rand() % 91 + 10; //random number of marbles
    int play;
    bool win = true;
    if (rand() % 2 == 0) //randomly decides who goes first
    {
        //if the computer goes first...
        //tell user how many marbles there are
        cout << "There are " << marbles << " marbles. The computer has been randomly selected to go first.\n";
        //get and process computer's move
        play = computer.getMove(marbles);
        marbles -= play;
        //output that information to user
        cout << "The computer removed " << play << " marbles, and there are " << marbles << " marbles remaining.\n";
    }
    else
    {
        //alert user that they are going first
        cout << "There are " << marbles << " marbles. You have been randomly selected to go first.\n";
    }

    while (marbles > 0) //while nobody has won the game
    {
        cout << "It is your turn. How many marbles would you like to remove?\n";
        //get user input
        cin >> play;
        if (marbles != 1) //if it's not 1...
        {
            //error checking for invalid inputs of marbles
            while (play > marbles / 2 || play <= 0)
            {
                cout << "\nThat is an invalid number of marbles. Please input a number of marbles between 1 and " << marbles / 2 << ":\n";
                cin >> play;
            }
        }
        else
        {
            //if there's 1 marble left and they didn't select to remove 1 marble, make them select to remove 1 marble
            if (play != 1)
                cout << "With 1 marble remaining, the only possible move is to remove 1 marble. That move has been made for you.\n";
            play = 1;
        }
        //remove the marble
        marbles -= play;

        cout << "There are " << marbles << " marbles remaining.\n";

        //check if there are no marbles left and user just lost
        if (marbles <= 0)
        {
            win = false;
            break;
        }

        //perform same actions for computer
        cout << "It is the computer's turn.\n";
        play = computer.getMove(marbles);
        marbles -= play;
        cout << "The computer removed " << play << " marbles, and there are " << marbles << " marbles remaining.\n";
    }

    //tell user if they won or not
    if (!win)
    {
        cout << "I'm sorry, you have lost to the computer. Better luck next time!\n";
    }
    else
        cout << "Congratulations, you have won against the computer!\n";

    return 0;
}