#include "Maze.h"

Maze::Maze(vector<vector<char> > fileContents) {

  startCol = -1;
  startRow = -1;
  for (int i = 0; i < fileContents[0].size() + 2; i++) {
    vector<char> temp(fileContents.size() + 2);
    maze.push_back(temp);
  }
  baseLength = maze[0].size() - 2;
  heightLength = maze.size() - 2;
  for (int i = 0; i < maze.size(); i++) {
    for (int j = 0; j < maze[0].size(); j++) {
      if (i == 0 || j == 0 || i == maze.size() - 1 || j == maze[0].size() - 1) {
        maze[i][j] = '*';
        continue;
      }
      maze[i][j] = fileContents[i - 1][j - 1];
      if (maze[i][j] == 'S' || maze[i][j] == 's') {
        startRow = i;
        startCol = j;
      }
    }
  }
}

ostream &operator<<(ostream &out, const Maze &printMaze) {
  // ignore the border ring
  for (int i = 1; i < printMaze.baseLength + 1; i++) {
    for (int j = 1; j < printMaze.heightLength + 1; j++) {
      // put the current value in the ostream, followed by a space
      out << printMaze.maze[i][j];
    }
    // after each row, put a new line in the ostream
    out << "\n";
  }
  // return the ostream
  return out;
}