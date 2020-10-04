#include "Matrix.h"

using namespace std;

Matrix::Matrix(vector<string> fileContents, bool isSecond) {
  matrixDim = stoi(fileContents[0]);
  string current;
  size_t pos;
  string match;
  int index;
  int start;
  int end;
  vector<int> row;

  if (!isSecond) {
    start = 1;
    end = matrixDim + 1;
  } else {
    start = matrixDim + 2;
    end = fileContents.size();
  }

  for (int i = start; i < end; i++) {
    current = fileContents[i];
    pos = 0;
    index = 0;
    row.clear();
    // while you can find a space and it's not equal to "no position"
    // function
    while ((pos = current.find(" ")) != current.npos) {
      match = current.substr(0, pos);
      row.push_back(stoi(match));
      current.erase(0, pos + 1); // pos+1 because delimiter length is 1
    }
    row.push_back(stoi(current));

    matrix.push_back(row);
  }

  matrixOp = fileContents[matrixDim + 1].at(3) - '0';
}

int Matrix::getOp() const { return matrixOp; }
