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

vector<vector<char> > getFileContents(string filePath) {
  vector<vector<char> > data; // raw input data from file
  ifstream infile(filePath);
  // infile.open(filePath); // open the filename defined above
  string line;

  // while there are lines to read in the file
  while (getline(infile, line)) {
    vector<char> current;
    for (int i = 0; i < line.length(); i++) {
      current.push_back(line.at(i));
    }
    // push those lines to the end of the vector
    data.push_back(current);
  }
  infile.close();
  return data;
}

int main(int argc, char *argv[]) {
  // if there isn't 1 argument (argv[0] is filename)
  if (argc != 2) {
    usage();  // display usage info
    return 0; // exit program
  }
  Maze maze(getFileContents(argv[1]));
  cout << "Maze Solved: " << boolalpha << maze.solve() << endl;
  cout << maze;
  return 0;
}