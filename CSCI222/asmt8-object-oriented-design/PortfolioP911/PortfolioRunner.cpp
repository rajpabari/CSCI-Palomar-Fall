#include "Portfolio.h"
#include <iostream>
using namespace std;

int main() {
  Portfolio portfolio;             // C balance: 0, S balance: 0
  portfolio.deposit(1000.0, "C");  // C balance: 1000, S balance: 0
  portfolio.withdraw(500.0, "C");  // C balance: 500, S balance: 0
  portfolio.deposit(2000.0, "S");  // C balance: 500, S balance: 2000
  portfolio.transfer(5000.0, "C"); // C balance: 490, S balance: 2000
  portfolio.transfer(390.0, "C");  // C balance: 100, S balance: 2390
  portfolio.printBalances();
  return 0;
}