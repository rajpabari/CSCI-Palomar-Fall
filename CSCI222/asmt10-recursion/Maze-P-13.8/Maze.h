#ifndef MAZE_H
#define MAZE_H
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Maze {
public:
  // Constructs a maze given a 2D character vector
  // @param fileContents 2D vector representing the maze
  Maze(vector<vector<char> > fileContents);

  // Checks if the maze is solveable
  // @return true if solveable, false if not
  bool isSolvable();
  // Overload << operator to print maze to an output stream
  // i thought this would be more useful than it is but whatever
  // @param out the ostream to output maze to
  // @param printMaze the maze to print out
  // @return ostream& an ostream with the maze printed and formatted on it
  friend ostream &operator<<(ostream &out, const Maze &printMaze);

private:
  vector<vector<char> > maze; // represents the maze
  // stores location of where to start
  int startRow;
  int startCol;

  // stores original lengths of maze to make syntax easier
  int baseLength;
  int heightLength;

  // true if maze solved, false if not
  bool hasWon;

  // recursively called function that gets a solution from the row and col to
  // the end
  // @param row the starting row
  // @param col the starting colum for the solution
  void getSolution(int row, int col);
};

#endif