#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Matrix {
public:
  Matrix(vector<string> fileContents, bool isSecond);
  int getOp() const;
  string print() const;

private:
  int matrixDim;
  int matrixOp;
  vector<vector<int> > matrix;
};

#endif