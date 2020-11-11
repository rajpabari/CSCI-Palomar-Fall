#include "BankAccount.h"

// didn't comment because code given by the book

BankAccount::BankAccount() { balance = 0; }

BankAccount::BankAccount(double initial_balance) { balance = initial_balance; }

void BankAccount::deposit(double amount) { balance = balance + amount; }

bool BankAccount::withdraw(double amount) {
  const double PENALTY = 10;
  if (amount > balance) {
    balance = balance - PENALTY;
    return false;
  } else {
    balance = balance - amount;
    return true;
  }
}
void BankAccount::add_interest(double rate) {
  double amount = balance * rate / 100;
  deposit(amount);
}
double BankAccount::get_balance() const { return balance; }
