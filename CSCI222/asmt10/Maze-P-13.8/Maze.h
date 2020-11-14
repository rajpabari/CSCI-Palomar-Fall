#ifndef MAZE_H
#define MAZE_H
#include "Square.h"
#include <iostream>
#include <vector>

using namespace std;

class Maze {
public:
  Maze(vector<vector<char> > fileContents);
  void solve();
  // Overload << operator to print matrix to an output stream
  // @param ostream &out the ostream to output matrix to
  // @param Matrix &printMatrix the matrix to print out
  // @return ostream& an ostream with the matrix printed and formatted on it
  friend ostream &operator<<(ostream &out, const Maze &printMaze);

private:
  vector<vector<char> > maze;
  int startRow;
  int startCol;
  int baseLength;
  int heightLength;
};

#endif