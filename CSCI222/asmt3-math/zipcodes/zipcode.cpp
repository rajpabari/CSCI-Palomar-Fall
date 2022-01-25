#include <iostream>
#include <string>

using namespace std;

/* Outputs the corresponding barcode to a digit of the ZIP code according to table in assignment
@param digit a digit of a ZIP code
@return string 5 character corresponding barcode 
*/
string getCode(int digit)
{
    switch (digit)
    {
    case 1:
        return ":::||";
    case 2:
        return "::|:|";
    case 3:
        return "::||:";
    case 4:
        return ":|::|";
    case 5:
        return ":|:|:";
    case 6:
        return ":||::";
    case 7:
        return "|:::|";
    case 8:
        return "|::|:";
    case 9:
        return "|:|::";
    case 0:
        return "||:::";
    default:
        return "||:::";
    }
}

int main()
{
    string input;
    int zipcode = 0;
    bool allDigits = false;

    //checks the user's input
    while (!allDigits || input.length() != 5)
    {
        //prompt and get user's input
        cout << "Input a 5-digit postal (ZIP) code:\n";
        cin >> input;
        //make sure that user inputted numbers
        try
        {
            zipcode = stoi(input);
            allDigits = true;
        }
        catch (std::invalid_argument)
        {
            allDigits = false;
        }
    }

    string ans = "|";
    //get each digit from the 5-digit ZIP code
    int digit1 = zipcode / 10000;
    int digit2 = (zipcode / 1000) % 10;
    int digit3 = (zipcode / 100) % 10;
    int digit4 = (zipcode / 10) % 10;
    int digit5 = ((zipcode * 10) % 100) / 10;

    //finds the nearest multiple of 10 that's greater than or equal to the sum of the digits
    //ie. if sum was 19 nearest multiple 10 would be 20
    //if sum was 20 nearest multiple would be 20
    int sum = digit1 + digit2 + digit3 + digit4 + digit5;
    int nearest10 = sum + 10;
    if (nearest10 % 10 == 0)
        nearest10 -= 10;
    else
        nearest10 -= nearest10 % 10;

    //finds check digit based on that information
    int checkDigit = nearest10 - sum;

    //calls method to generate the code
    ans += getCode(digit1);
    ans += getCode(digit2);
    ans += getCode(digit3);
    ans += getCode(digit4);
    ans += getCode(digit5);
    ans += getCode(checkDigit);
    ans += "|";

    //output and exit
    cout << "The corresponding barcode is: " << ans << "\n";
    return 0;
}