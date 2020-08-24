#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello, my name is Hal\nWhat is your name?\n";

    //get user input and respond
    string user_name;
    getline(cin, user_name);

    //use input and exit program
    cout << "Hello, " + user_name + "! Nice to meet you.\n";
    return 0;
}