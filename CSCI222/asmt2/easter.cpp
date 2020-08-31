#include <iostream>

using namespace std;

string getMonth(int num)
{
    //input: int num, number month of the year (ie 1)
    //output: string representing the corresponding month of the year (ie January)
    switch (num)
    {
    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;
    case 3:
        return "March";
        break;
    case 4:
        return "April";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "June";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "August";
        break;
    case 9:
        return "September";
        break;
    case 10:
        return "October";
        break;
    case 11:
        return "November";
        break;
    case 12:
        return "December";
        break;
    default:
        return "April";
    }
}

int main()
{
    //get user input
    int y;
    cout << "What year are you in?\n";
    cin >> y;

    //perform gauss's algorithm
    int a = y % 19;
    int b = y / 100;
    int c = y % 100;
    int d = b / 4;
    int e = b % 4;
    int g = (8 * b + 13) / 25;
    int h = (19 * a + b - d - g + 15) % 30;
    int j = c / 4;
    int k = c % 4;
    int m = (a + 11 * h) / 319;
    int r = (2 * e + 2 * j - k - h + m + 32) % 7;
    int n = (h - m + r + 90) / 25;
    int p = (h - m + r + 19 + n) % 32;

    //output and exit program
    cout << "Easter in " << y << " falls on " << getMonth(n) << " " << p << "\n";
    return 0;
}