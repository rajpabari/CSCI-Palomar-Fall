#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// gets the contents of the file located at filePath
//@param string filePath the path to the file
//@return the contents of the file in a string vector
vector<string> getFileContents(string filePath) {
  vector<string> data; // raw input data from file
  ifstream infile;
  infile.open(filePath); // open the filename supplied
  string line;

  // while there are lines to read in the file
  while (getline(infile, line)) {
    // push those lines to the end of the vector
    data.push_back(line);
  }
  infile.close();
  // return our vector
  return data;
}

// Display usage information to cout
void usage() {
  cout << "Input path to graph input file in command line" << endl;
  cout << "Example: g++ GraphRunner.cpp ./CSCI222/lab5/GraphInput1.txt" << endl;
  cout
      << "note: file format is as follows"
         "\nline 1: vertex data type (\"string\" & \"int\" currently "
         "supported)\n "
         "line 2: \"directed\" or \"undirected\" graph\n\nrest of lines define "
         "edges in format: vertexFrom vertexTo weight\nexample: A B "
         "3.5\nexample: hotdog burger 5.3\nexample: 4 2 3.4"
      << endl;
}

int main(int argc, char const *argv[]) {
  // if there isn't 1 argument (argv[0] is filename)
  if (argc != 2) {
    usage();  // display usage info
    return 0; // exit program
  }
  vector<string> fileContents = getFileContents(argv[1]);
  return 0;
}
