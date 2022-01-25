#include "Maze.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Display usage information to cout
void usage() {
  cout << "Input name of file in command line" << endl;
  cout << "Example: g++ MazeRunner.cpp maze1.txt" << endl;
}

// gets the contents of the file located at filePath
//@param string filePath the path to the file
//@return the contents of the file in a 2D char vector
vector<vector<char> > getFileContents(string filePath) {
  vector<vector<char> > data; // raw input data from file
  ifstream infile(filePath);  // open the file at filePath
  string line;

  // while there are lines to read in the file
  while (getline(infile, line)) {
    // put each character of the line into a temporary vector
    vector<char> current;
    for (int i = 0; i < line.length(); i++) {
      current.push_back(line.at(i));
    }
    // push those characters to the end of the 2D return vector
    data.push_back(current);
  }
  // close our file
  infile.close();
  // return our 2D vector
  return data;
}

int main(int argc, char *argv[]) {
  // if there isn't 1 argument (argv[0] is filename)
  if (argc != 2) {
    usage();  // display usage info
    return 0; // exit program
  }
  // make our maze
  Maze maze(getFileContents(argv[1]));
  // check if there is a solution
  cout << "Maze Solved: " << boolalpha << maze.isSolvable() << endl;
  // print out the modified maze to cout to confirm it's doing the algorithm
  cout << maze;
  return 0;
}