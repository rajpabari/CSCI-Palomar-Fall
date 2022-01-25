#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include "BankAccount.h"
#include <iomanip>
#include <iostream>

using namespace std;

class Portfolio {

public:
  // deposit an amount of money into one of the accounts
  // @param double amount the amount of money to deposit
  // @param string account the account to deposit into
  // for account: "C" = checking, "S" = savings
  // @return bool true if success, false if failure
  bool deposit(double amount, string account);

  // withdraw an amount of money from one of the accounts
  // @param double amount the amount of money to withdraw
  // @param string account the account to withdraw from
  // for account: "C" = checking, "S" = savings
  // @return bool true if success, false if failure

  bool withdraw(double amount, string account);

  // transfer an amount of money from one of the accounts to another
  // @param double amount the amount of money to transfer
  // @param string account the account to transfer from
  // for account: "C" = checking, "S" = savings
  // @return bool true if success, false if failure or penalty assessed
  bool transfer(double amount, string account);

  // prints all of the balances of all the accounts
  // @param none
  // @return none
  void printBalances();

private:
  BankAccount checking;
  BankAccount savings;
};

#endif