#include "Portfolio.h"

bool Portfolio::deposit(double amount, string account) {
  // if it's C, deposit into checking
  if (account == "C") {
    checking.deposit(amount);
  }
  // if it's S, deposit into savings
  else if (account == "S") {
    savings.deposit(amount);
  }
  // otherwise, account isn't supported so return false
  else
    return false;
  // return true by default
  return true;
}

bool Portfolio::withdraw(double amount, string account) {
  // if it's C, withdraw from checking
  if (account == "C") {
    checking.withdraw(amount);
  }
  // if it's S, withdraw from savings
  else if (account == "S") {
    savings.withdraw(amount);
  }
  // otherwise, account isn't supported so return false
  else
    return false;
  // return true by default
  return true;
}

bool Portfolio::transfer(double amount, string account) {
  // if it's C, transfer from checking to savings
  if (account == "C") {
    // withdraw from checking
    if (checking.withdraw(amount)) {
      // if it returned true, checking account had sufficient funds
      // so deposit the amount into savings
      savings.deposit(amount);
    } else {
      // if it returned false, there were insufficient funds so a penalty was
      // assessed and don't transfer anything to savings
      // so return false for failure
      return false;
    }
  }
  // same as above but savings and checking switch places
  else if (account == "S") {
    if (savings.withdraw(amount)) {
      checking.deposit(amount);
    } else {
      return false;
    }
  }
  // otherwise account not supported
  else
    return false;
  // return success by default
  return true;
}

void Portfolio::printBalances() {
  // print each with 2 decimal places
  cout << "Checking Balance: $" << fixed << setprecision(2)
       << checking.get_balance() << endl;
  cout << "Savings Balance: $" << fixed << setprecision(2)
       << savings.get_balance() << endl;
}
