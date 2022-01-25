#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

  // initialize vars
  string input;
  string ans = "";
  stack<string> ops;

  // tell user how to use this
  cout << "input space-separated infix expression, supported operators are "
          "+,-,*,/, p to print, q to quit"
       << endl
       << endl;

  // while the user is inputting stuff, store it to input variable
  while (cin >> input) {

    // if it's a number or a negative number,
    // add it directly to the answer
    if ((input.at(0) >= '0' && input.at(0) <= '9') ||
        (input.at(0) == '-' && input.size() > 1)) {
      ans += input + " ";
    }
    // if it's p, it means print our postfix expression
    else if (input == "p") {
      // while the stack isnt empty...
      while (!ops.empty()) {
        // add the top value to the output string
        ans += ops.top() + " ";
        // and pop that operator off the output string
        ops.pop();
      }

      // print the output string
      cout << ans << endl << endl;

      // reset output string
      ans = "";
    }
    // if it's q, return 0 to quit
    else if (input == "q") {
      return 0;
    }
    // if it's an open parenthesis, just push it to the stack every time
    else if (input == "(") {
      ops.push(input);
    }
    // if it's a close parenthesis
    else if (input == ")") {
      // push all operators off up until the corresponding open parenthesis
      while (!ops.empty() && ops.top() != "(") {

        // and along the way add the operators to the output string
        ans += ops.top() + " ";
        ops.pop();
      }

      // pop off the top which is the open parenthesis b/c it's been taken care
      // of
      ops.pop();
    }
    // otherwise it's an operator
    else {
      // if it's + or -
      if (input == "+" || input == "-") {

        // while if it's not empty stack and the top is not a parenthesis
        while (!ops.empty() && (ops.top() == "*" || ops.top() == "/" ||
                                ops.top() == "+" || ops.top() == "-")) {
          // add operator from top of stack to output string, and pop it off
          ans += ops.top() + " ";
          ops.pop();
        }

        // push this operator on
        ops.push(input);
      }
      // if it's * or /
      else {

        // if stack isn't empty and the top is either * or /
        // note not + or - because they get evaluated after * and /
        while (!ops.empty() && (ops.top() == "*" || ops.top() == "/")) {
          // add operator from top of stack to output string, and pop it off
          ans += ops.top() + " ";
          ops.pop();
        }

        // push this operator on
        ops.push(input);
      }
    }
  }

  return 0;
}