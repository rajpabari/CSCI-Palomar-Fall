#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Display usage information to cout
// @param none
// @return none
void usage() {
  cout << "Input name of file in command line" << endl;
  cout << "Example: g++ MatrixRunner.cpp matrix1.txt" << endl;
}

// Driver code for Matrix operations
// @param int argc the number of arguments
// @param char *argv[] char* array representing the arguments passed in
// @return 0 for success, 1 or other for failure/error
int main(int argc, char *argv[]) {
  // if there isn't 1 argument (argv[0] is filename)
  if (argc != 2) {
    usage();  // display usage info
    return 0; // exit program
  }

  vector<string> data; // raw input data from file
  ifstream infile;
  infile.open(argv[1]); // open the filename supplied
  string line;

  // while there are lines to read in the file
  while (getline(infile, line)) {
    // push those lines to the end of the vector
    data.push_back(line);
  }

  // construct the first matrix
  Matrix matrix1(data, false);
  // get the matrix operation number
  // matrix1.getDim() + 1 is the dimensions of the matrix + 1
  // data[that^] will be the line that has format "op X"
  // the 3rd character in that line is X which will be some number
  // subtract the char value of 0 from it to get an int value
  int matrixOp = data[matrix1.getDim() + 1].at(3) - '0';

  // print matrix1 to cout using overloaded operator
  cout << "MATRIX 1:\n" << matrix1 << endl;

  // if the op is <= 3, there's a second matrix to read!
  if (matrixOp <= 3) {
    // read that second matrix
    Matrix matrix2(data, true);
    // print matrix1 to cout using overloaded operator
    cout << "MATRIX 2:\n" << matrix2 << endl;
    // perform operation
    switch (matrixOp) {
    case 1: {
      // perform addition using overloaded operator
      cout << "op 1 - add\nANSWER MATRIX:\n" << matrix1 + matrix2 << endl;
      return 0;
    }
    case 2: {
      // perform subtraction using overloaded operator
      cout << "op 2 - subtract\nANSWER MATRIX:\n" << matrix1 - matrix2 << endl;
      return 0;
    }
    case 3: {
      // perform multiplication using overloaded operator
      cout << "op 3 - mult\nANSWER MATRIX:\n" << matrix1 * matrix2 << endl;
      return 0;
    }
    }
  }

  // perform operation
  switch (matrixOp) {
  case 7: {
    // perform exponent using overloaded operator
    // note: data[data.size() - 1] is last line of file
    // stoi(that^) is integer of that string
    cout << "op 7 - exponent\npower: " << stoi(data[data.size() - 1])
         << "\nANSWER MATRIX:\n"
         << (matrix1 ^ stoi(data[data.size() - 1])) << endl;
    return 0;
  }
  case 8: {
    // print matrix using overloaded operator
    cout << "op 8 - print matrix\nANSWER MATRIX:\n" << matrix1 << endl;
    return 0;
  }
  case 4: {
    // perform post and pre increment using overloaded operator
    // this print, the value should not be changed!
    cout << "op 4 - increment matrix\nANSWER MATRIX:\npostfix:\n"
         << matrix1++ << endl;
    // then it should be changed here
    cout << "After calling postfix:\n" << matrix1 << endl;
    // and with prefix it should print the changed one
    cout << "Prefix:\n" << ++matrix1 << endl;
    return 0;
  }
  case 5: {
    // perform post and pre decrement using overloaded operator
    // this print, the value should not be changed!
    cout << "op 5 - decrement matrix\nANSWER MATRIX:\npostfix:\n"
         << matrix1-- << endl;
    // then it should be changed here
    cout << "After calling postfix:\n" << matrix1 << endl;
    // and with prefix it should print the changed one
    cout << "Prefix:\n" << --matrix1 << endl;
    return 0;
  }
  case 6: {
    // perform matrix transpose using overloaded operator
    cout << "op 6 - transpose matrix\nANSWER MATRIX:\n" << ~matrix1 << endl;
    return 0;
  }
  default: {
    // if it was none of these cases, it's not a supported operation number
    cout << "Operation not supported!" << endl;
    // return 1 for error
    return 1;
  }
  }

  return 0;
}