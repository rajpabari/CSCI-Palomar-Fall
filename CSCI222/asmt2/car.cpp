#include <iostream>
#include <cmath>

using namespace std;

/*PSEUDOCODE:
input cost of new hybrid car
input resale value of hybrid after 5 years
input mileage for hybrid
input cost of new environment-killing car
input resale value of gas guzzler after 5 years
input mileage of gas car
input estimated miles driven per year
input gas price

set hybrid cost equal to cost + ((miles driven / mileage) * 5 years)*gas price - value after 5 years
set gas cost equal to cost + ((miles driven / mileage) * 5 years)*gas price - value after 5 years

output cost of hybrid car
output cost of gas car

if hybrid cost > gas cost:
    output you should buy a gas car
else:
    output you should buy a hybrid car

END PSEUDOCODE
*/
int main()
{
    //get inputs
    cout << "What is the cost of some hybrid car?\n";
    int hybridCost;
    cin >> hybridCost;

    cout << "\nWhat is the resale value of that hybrid car after 5 years?\n";
    int hybridValue;
    cin >> hybridValue;

    cout << "\nWhat is the mileage of that hybrid car?\n";
    double hybridMileage;
    cin >> hybridMileage;

    cout << "\nWhat is the cost of some non-hybrid car?\n";
    int gasCost;
    cin >> gasCost;

    cout << "\nWhat is the resale value of that non-hybrid car after 5 years?\n";
    int gasValue;
    cin >> gasValue;

    cout << "\nWhat is the mileage of that non-hybrid car?\n";
    double gasMileage;
    cin >> gasMileage;

    cout << "\nHow many miles do you drive each year?\n";
    int milesDriven;
    cin >> milesDriven;

    cout << "\nWhat is the price of gas?\n";
    double gasPrice;
    cin >> gasPrice;

    //calculate total cost of both cars
    double hybridTotalCost = hybridCost + ((milesDriven / hybridMileage) * 5) * gasPrice - hybridValue;
    double gasTotalCost = gasCost + ((milesDriven / gasMileage) * 5) * gasPrice - gasValue;

    //output total costs
    cout << "\nThe total cost of your hybrid car after 5 years will be $" << round(hybridTotalCost) << ",\nand the total cost of your non-hybrid car after 5 years will be $" << round(gasTotalCost);

    //compare and draw a conclusion
    if (hybridTotalCost > gasTotalCost)
    {
        cout << "\nIf you will own a car for 5 years, you should purchase the non-hybrid car.\n";
    }
    else
    {
        cout << "\nIf you will own a car for 5 years, you should purchase the hybrid car.\n";
    }
}