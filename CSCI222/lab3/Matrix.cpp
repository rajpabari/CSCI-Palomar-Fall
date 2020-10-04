#include "Matrix.h"

using namespace std;

Matrix::Matrix(vector<string> fileContents, bool isSecond) {
  // create many temporary vars that will be useful later
  string current;
  size_t pos;
  string match;
  int index;
  int start;
  int end;
  vector<int> row;

  // string to integer of the first line of the file
  // this is the dimension of the matrix
  matrixDim = stoi(fileContents[0]);

  // if it's the first matrix...
  if (!isSecond) {
    // first line of matrix is line 1, last is matrix dimension (add 1 bc
    // strictly less than)
    start = 1;
    end = matrixDim + 1;
  }
  // if its the second matrix in the file...
  else {
    // first line of matrix is line matrix dimension +2, last is last line of
    // file - 1 (add 1 bc strictly less than)
    start = matrixDim + 2;
    end = fileContents.size();
  }

  // for each line of the matrix
  for (int i = start; i < end; i++) {
    current = fileContents[i]; // current line of the file
    // reset variables
    pos = 0;
    index = 0;
    row.clear();

    // while you can find a space and it's not equal to "no position"
    // function, space is the delimiter
    while ((pos = current.find(" ")) != current.npos) {
      // match is the substing between the beginning of line and delimiter index
      match = current.substr(0, pos);

      // push the integer value of the match string to the end of this row of
      // matrix
      row.push_back(stoi(match));
      // erase the string up to & including the delimiter
      current.erase(0, pos + 1); // pos+1 because delimiter length is 1
    }
    // push the integer value of the remaining string (also a match) to the end
    // of this row of matrix
    row.push_back(stoi(current));

    // push the completed row to the 2D vector of our matrix
    matrix.push_back(row);
  }
}

Matrix::Matrix(vector<vector<int> > matrixContents) {
  // if we're given that 2D vector already, it's a lot less work
  matrix = matrixContents;           // matrix is that 2D vector
  matrixDim = matrixContents.size(); // dimensions is the size of that vector
}

int Matrix::getDim() const { return matrixDim; }

vector<int> Matrix::getRow(int row) const { return matrix[row]; }

vector<int> Matrix::getCol(int col) const {
  // create a vector that will represent the column
  vector<int> ans(matrixDim);
  for (int i = 0; i < matrixDim; i++) {
    // go vertically through the matrix to push in each value in the column
    ans.push_back(matrix[i][col]);
  }
  return ans;
}

Matrix &operator++(Matrix &mat) {
  // for each value in the matrix
  for (int i = 0; i < mat.matrixDim; i++) {
    for (int j = 0; j < mat.matrixDim; j++) {
      // increment it by 1
      mat.matrix[i][j] += 1;
    }
  }

  // return the incremented matrix
  return mat;
}

Matrix &operator++(Matrix &mat, int unused) {
  // save the unchanged matrix bc postfix
  Matrix &ans = *(new Matrix(mat.matrix));
  // for each value in the matrix
  for (int i = 0; i < mat.matrixDim; i++) {
    for (int j = 0; j < mat.matrixDim; j++) {
      // increment it by 1
      mat.matrix[i][j] += 1;
    }
  }
  // return the unchanged matrix
  return ans;
}

Matrix &operator--(Matrix &mat) {
  // for each value in the matrix
  for (int i = 0; i < mat.matrixDim; i++) {
    for (int j = 0; j < mat.matrixDim; j++) {
      // decrement by 1
      mat.matrix[i][j] -= 1;
    }
  }

  // return decremented matrix
  return mat;
}

Matrix &operator--(Matrix &mat, int unused) {
  // save the unchanged matrix bc postfix
  Matrix &ans = *(new Matrix(mat.matrix));
  // for each value in the matrix
  for (int i = 0; i < mat.matrixDim; i++) {
    for (int j = 0; j < mat.matrixDim; j++) {
      // decrement each by 1
      mat.matrix[i][j] -= 1;
    }
  }
  // return the unchanged matrix

  return ans;
}

Matrix operator+(const Matrix &matrix1, const Matrix &matrix2) {
  vector<vector<int> > ans; // answer (kinda)
  vector<int> current;      // current row

  // for each row
  for (int i = 0; i < matrix1.getDim(); i++) {
    // clear current row to reset
    current.clear();

    // for each column
    for (int j = 0; j < matrix2.getDim(); j++) {
      // push the sum of the two matrices at that row and column to the row
      current.push_back(matrix1.getRow(i)[j] + matrix2.getRow(i)[j]);
    }
    // once the row has been made, push to back of the answer
    ans.push_back(current);
  }

  // construct a matrix with those contents and return it
  return Matrix(ans);
}

Matrix operator-(const Matrix &matrix1, const Matrix &matrix2) {
  // exactly the same as addition above, except for this one change:

  vector<vector<int> > ans;
  vector<int> current;
  for (int i = 0; i < matrix1.getDim(); i++) {
    current.clear();
    for (int j = 0; j < matrix2.getDim(); j++) {
      // here, change the + to a - because subtracting the two matrices
      current.push_back(matrix1.getRow(i)[j] - matrix2.getRow(i)[j]);
    }
    ans.push_back(current);
  }
  return Matrix(ans);
}

Matrix operator*(const Matrix &matrix1, const Matrix &matrix2) {
  // this stuff is same as previous two
  vector<vector<int> > ans;
  vector<int> current;
  // need to make a cell value because multiplication is the sum of some dot
  // products
  int cell;
  for (int x = 0; x < matrix1.getDim(); x++) {
    // clear the row
    current.clear();
    for (int i = 0; i < matrix1.getDim(); i++) {
      // reset the cell value
      cell = 0;
      for (int j = 0; j < matrix2.getDim(); j++) {
        // this is just like how matrix multiplication works
        // you take each row of the first and multiply by each col of the second
        cell += matrix1.getRow(x)[j] * matrix2.getRow(j)[i];
      }
      // add cell to the row
      current.push_back(cell);
    }
    // add row to ans
    ans.push_back(current);
  }

  // construct a matrix with those contents and return it
  return Matrix(ans);
}

Matrix operator^(const Matrix &matrix1, const int &exp) {
  Matrix ans = matrix1;
  // multiply the matrix by itself exp times
  for (int i = 0; i < exp - 1; i++) {
    ans = ans * matrix1;
  }
  return ans;
}

Matrix operator~(const Matrix &matrix1) {
  // same as before
  vector<vector<int> > ans;
  vector<int> current;
  // for each cell
  for (int i = 0; i < matrix1.getDim(); i++) {
    current.clear(); // reset row
    for (int j = 0; j < matrix1.getDim(); j++) {
      // transposing is flipping the row and the column, so do that
      current.push_back(matrix1.getRow(j)[i]);
    }
    // add this row to the answer
    ans.push_back(current);
  }

  // construct and return it
  return Matrix(ans);
}

ostream &operator<<(ostream &out, const Matrix &printMatrix) {
  for (int i = 0; i < printMatrix.getDim(); i++) {
    for (int j = 0; j < printMatrix.getDim(); j++) {
      // put the current value in the ostream, followed by a space
      out << printMatrix.getRow(i)[j];
      out << " ";
    }
    // after each row, put a new line in the ostream
    out << "\n";
  }
  // return the ostream
  return out;
}