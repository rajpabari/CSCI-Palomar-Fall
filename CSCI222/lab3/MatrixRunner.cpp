#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INPUT_SIZE 100

void usage() {
  cout << "Input name of file in command line" << endl;
  cout << "Example: g++ MatrixRunner.cpp matrix1.txt" << endl;
}

int main(int argc, char *argv[]) {
  vector<string> data;
  ifstream infile;
  infile.open(argv[1]);

  if (argc != 2) {
    usage();
    return 0;
  }

  string line;
  int counter = 0;
  while (getline(infile, line)) {
    data.push_back(line);
  }

  Matrix matrix1(data, false);
  cout << matrix1.getOp() << endl;
  if (matrix1.getOp() <= 3) {
    Matrix matrix2(data, true);
  }
  // TODO: switch (matrix1.getOp()) {}

  return 0;
}