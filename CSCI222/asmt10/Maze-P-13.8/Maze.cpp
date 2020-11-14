#include "Maze.h"

Maze::Maze(vector<vector<char> > fileContents) {
  // initializes these variables
  startCol = -1;
  startRow = -1;
  hasWon = false;

  // initialize the maze to have an extra row and column for border
  for (int i = 0; i < fileContents[0].size() + 2; i++) {
    vector<char> temp(fileContents.size() + 2);
    maze.push_back(temp);
  }
  // set the original base length and height length of the maze
  baseLength = maze[0].size() - 2;
  heightLength = maze.size() - 2;

  // for every location in the maze
  for (int i = 0; i < maze.size(); i++) {
    for (int j = 0; j < maze[0].size(); j++) {
      // if it's the first or last row or column, it should be a border wall
      if (i == 0 || j == 0 || i == maze.size() - 1 || j == maze[0].size() - 1) {
        maze[i][j] = '*';
        continue;
      }

      // otherwise, it should be whatever was at that location originally
      maze[i][j] = fileContents[i - 1][j - 1];
      // if it's the start position, store the row and column for future use
      if (maze[i][j] == 'S' || maze[i][j] == 's') {
        startRow = i;
        startCol = j;
      }
    }
  }
}

bool Maze::isSolvable() {
  // attempt to get a solution and start at the initial row and column
  getSolution(startRow, startCol);
  // reset the square to S for output purposes
  maze[startRow][startCol] = 'S';
  // return true if solved, false if not
  return hasWon;
}

void Maze::getSolution(int row, int col) {
  // for loops check each value of up down left and right
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      // however we can't move diagonally or not at all, so ignore those cases
      if (abs(j) == abs(i))
        continue;

      // if we are one step away from the finish
      if (maze[row + i][col + j] == 'F' || maze[row + i][col + j] == 'f') {
        // we won the maze
        hasWon = true;
        // stop trying to get the solution
        return;
      }
      // if there's an empty space we can go to
      else if (maze[row + i][col + j] == ' ') {
        // mark that we have gone to that space
        maze[row + i][col + j] = 'x';
        // try to get a solution from there
        getSolution(row + i, col + j);
      }
    }
  }
}

ostream &operator<<(ostream &out, const Maze &printMaze) {
  // ignore the border ring
  for (int i = 1; i < printMaze.baseLength + 1; i++) {
    for (int j = 1; j < printMaze.heightLength + 1; j++) {
      // put the current value in the ostream
      out << printMaze.maze[i][j];
    }
    // after each row, put a new line in the ostream
    out << "\n";
  }
  // return the ostream
  return out;
}