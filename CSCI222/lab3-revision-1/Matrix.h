#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Matrix {
public:
  // Constructs a matrix object given raw file data
  // @param vector<string> fileContents the raw contents of a file in input
  // format as described in lab
  // @param bool isSecond true if it's the second matrix, false if not
  // @return none
  Matrix(vector<string> fileContents, bool isSecond);

  // Constructs a matrix object given the contents of the matrix
  // @param vector<vector<int> > matrixContents 2D vector with values of matrix
  // @return none
  Matrix(vector<vector<int> > matrixContents);

  // gets the dimensions of the matrix
  // @param none
  // @return int dimension of the matrix
  int getDim() const;

  // gets a given row of the matrix
  // @param int row the row to get from the matrix
  // @return vector<int> the requested row
  vector<int> getRow(int row) const;

  // gets a given column of the matrix
  // @param int col the column to get from the matrix
  // @return vector<int> the requested column
  vector<int> getCol(int col) const;

  // Friend functions!

  // Prefix increment - increments each value of matrix by 1,
  // then returns the incremented matrix
  // @param none
  // @return Matrix& pointer to incremented matrix
  Matrix &operator++();

  // postfix increment - increments each value of matrix by 1,
  // then returns the original matrix
  // @param int unused to distinguish between pre and post fix
  // @return Matrix copy of the original matrix
  Matrix operator++(int);

  // Prefix decrement - decrement each value of matrix by 1,
  // then returns the decremented matrix
  // @param none
  // @return Matrix& pointer to decremented matrix
  Matrix &operator--();

  // postfix decrement - decrement each value of matrix by 1,
  // then returns the original matrix
  // @param int unused to distinguish between pre and post fix
  // @return Matrix copy of original matrix
  Matrix operator--(int);

private:
  int matrixDim;               // dimension of the matrix
  vector<vector<int> > matrix; // 2D vector representing the matrix values
};

// overloaded operators

// Adds two matrices via standard matrix addition
// @param Matrix &matrix1 first matrix to add
// @param Matrix &matrix2 second matrix to add
// @return Matrix new matrix being the sum of the other two
Matrix operator+(const Matrix &matrix1, const Matrix &matrix2);

// Subtracts two matrices via standard matrix subtraction
// @param Matrix &matrix1 first matrix
// @param Matrix &matrix2 second matrix to subtract from matrix1
// @return Matrix new matrix being the difference of the other two
Matrix operator-(const Matrix &matrix1, const Matrix &matrix2);

// Multiplies two matrices via standard matrix multiplication
// @param Matrix &matrix1 first matrix
// @param Matrix &matrix2 second matrix to multiply by matrix1
// @return Matrix new matrix being the product of the other two
Matrix operator*(const Matrix &matrix1, const Matrix &matrix2);

// Positive exponential - multiplies matrix1 by itself exp number of times
// @param Matrix &matrix1 matrix to be exponentiated
// @param int &exp power to raise it to
// in other words, number of times to multiply it by itself
// @return Matrix new matrix being the exponentiated matrix
Matrix operator^(const Matrix &matrix1, const int &exp);

// Transpose - flip the rows and columns of matrix1
// @param Matrix &matrix1 matrix to be transposed
// @return Matrix new matrix being the transposed matrix
Matrix operator~(const Matrix &matrix1);

// Overload << operator to print matrix to an output stream
// @param ostream &out the ostream to output matrix to
// @param Matrix &printMatrix the matrix to print out
// @return ostream& an ostream with the matrix printed and formatted on it
ostream &operator<<(ostream &out, const Matrix &printMatrix);

#endif