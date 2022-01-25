#include <iostream>
#include <string>

using namespace std;

int main()
{
    //ask user for input
    cout << "Hello, my name is Hal\nWhat would you like me to do?\n";

    //get user input and respond
    string user_input;
    getline(cin, user_input);
    cout << "I am sorry, I cannot do that.\n";

    //end program
    return 0;
}