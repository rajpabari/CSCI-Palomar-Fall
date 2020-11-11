#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
using namespace std;
/**
   A bank account whose balance can be changed by deposits and withdrawals.
*/
class BankAccount {
public:
  /**
     Constructs a bank account with zero balance.
*/
  BankAccount();
  /**
     Constructs a bank account with a given balance.
     @param initial_balance the initial balance
  */
  BankAccount(double initial_balance);
  /**
     Makes a deposit into this account.
     @param amount the amount of the deposit
  */
  void deposit(double amount);
  /**
     Makes a withdrawal from this account, or charges a penalty if
     sufficient funds are not available.
     @param amount the amount of the withdrawal
     @return bool true if no penalty assessed, false if penalty assessed
  */
  bool withdraw(double amount);
  /**
     Adds interest to this account.
     @param rate the interest rate in percent
*/
  void add_interest(double rate);
  /**
     Gets the current balance of this bank account.
     @return the current balance
  */
  double get_balance() const;

private:
  double balance;
};

#endif