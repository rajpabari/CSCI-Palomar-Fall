#include "Graph.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

// gets the contents of the file located at filePath
//@param string filePath the path to the file
//@return the contents of the file in a string vector
vector<tuple<int *, int *, double> > getFileContentsIntData(string filePath) {
  vector<tuple<int *, int *, double> > data; // raw input data from file
  ifstream infile;
  infile.open(filePath); // open the filename supplied
  string line;
  string word;
  int numWordsRead;
  map<int, int *> uniqueData;

  // while there are lines to read in the file
  while (getline(infile, line)) {
    numWordsRead = 0;
    // if its the first line of the file ignore it for vector making purposes
    if (line == "directed" || line == "undirected")
      continue;
    tuple<int *, int *, double> current;
    // read each word of the line using an input string stream
    istringstream iss(line, istringstream::in);
    // while there's a word to read on this line
    while (iss >> word) {
      if (numWordsRead == 0) {
        if (uniqueData.find(stoi(word)) != uniqueData.end()) {
          get<0>(current) = uniqueData[stoi(word)];
        } else {
          int *newInt = new int;
          *newInt = stoi(word);
          get<0>(current) = newInt;
          uniqueData[stoi(word)] = newInt;
        }
      } else if (numWordsRead == 1) {
        if (uniqueData.find(stoi(word)) != uniqueData.end()) {
          get<1>(current) = uniqueData[stoi(word)];
        } else {
          int *newInt = new int;
          *newInt = stoi(word);
          get<1>(current) = newInt;
          uniqueData[stoi(word)] = newInt;
        }
      } else {
        double weight = stod(word);
        get<2>(current) = weight;
      }
      numWordsRead++;
    }
    // push those lines to the end of the vector
    data.push_back(current);
  }
  infile.close();
  // return our vector
  return data;
}

bool isDirected(string filePath) {
  ifstream infile;
  infile.open(filePath);
  string line;
  getline(infile, line);
  infile.close();
  if (line == "directed")
    return true;
  else
    return false;
}

vector<tuple<string *, string *, double> >
getFileContentsStringData(string filePath) {
  vector<tuple<string *, string *, double> > data; // raw input data from file
  ifstream infile;
  infile.open(filePath); // open the filename supplied
  string line;
  string word;
  int numWordsRead;
  map<string, string *> uniqueData;

  // while there are lines to read in the file
  while (getline(infile, line)) {
    numWordsRead = 0;
    // if its the first line of the file ignore it for vector making purposes
    if (line == "directed" || line == "undirected")
      continue;
    tuple<string *, string *, double> current;
    // read each word of the line using an input string stream
    istringstream iss(line, istringstream::in);
    // while there's a word to read on this line
    while (iss >> word) {
      if (numWordsRead == 0) {
        if (uniqueData.find(word) != uniqueData.end()) {
          get<0>(current) = uniqueData[word];
        } else {
          string *newWord = new string(word);
          get<0>(current) = newWord;
          uniqueData[word] = newWord;
        }
      } else if (numWordsRead == 1) {
        if (uniqueData.find(word) != uniqueData.end()) {
          get<1>(current) = uniqueData[word];
        } else {
          string *newWord = new string(word);
          get<1>(current) = newWord;
          uniqueData[word] = newWord;
        }
      } else {
        double weight = stod(word);
        get<2>(current) = weight;
      }
      numWordsRead++;
    }
    // push those lines to the end of the vector
    data.push_back(current);
  }
  infile.close();
  // return our vector
  return data;
}

// Display usage information to cout
void usage() {
  cout << "Input path to graph input file 1 and 2 in command line" << endl;
  cout << "Example: g++ GraphRunner.cpp ./CSCI222/lab5/GraphInput1.txt "
          "./CSCI222/lab5/GraphInput2.txt ./CSCI222/lab5/GraphInput3.txt"
       << endl;
  cout << "note: file format is as follows"
          "line 1: \"directed\" or \"undirected\" graph\n\nrest of lines "
          "define "
          "edges in format: vertexFrom vertexTo weight\nexample: A B "
          "3.5\nexample: hotdog burger 5.3\nexample: 4 2 3.4"
       << endl;
}

int main(int argc, char const *argv[]) {
  // if there isn't 3 arguments (argv[0] is filename)
  if (argc != 4) {
    usage();  // display usage info
    return 0; // exit program
  }

  cout << "-------------TESTING WITH STRING GRAPH (INPUT 1)-------------"
       << endl;
  vector<tuple<string *, string *, double> > stringFileContents =
      getFileContentsStringData(argv[1]);
  Graph<string> stringGraph(stringFileContents, isDirected(argv[1]));
  cout << "ORIGINAL STRING GRAPH:" << endl;
  cout << stringGraph;
  string *toReplace = new string("lettuce");
  cout << "Replacing vertex " << *stringGraph.getData(0) << " with "
       << *toReplace << endl;
  stringGraph.replaceVertexData(stringGraph.getData(0), toReplace);

  string *toAdd = new string("zucchini");
  cout << "Adding vertex " << *toAdd << endl;
  stringGraph.addVertex(toAdd);
  cout << "Adding edge from " << *toAdd << " to " << *toReplace
       << " with weight 2.2" << endl;
  stringGraph.addEdge(toAdd, toReplace, 2.2);
  cout << "Adding edge from " << *toAdd << " to " << *stringGraph.getData(2)
       << " with weight 4.9" << endl;
  stringGraph.addEdge(toAdd, stringGraph.getData(2), 4.9);
  cout << "MODIFIED STRING GRAPH:" << endl;
  cout << stringGraph;

  cout << "-------------TESTING WITH INT GRAPH (INPUT 2)-------------" << endl;
  vector<tuple<int *, int *, double> > intFileContents =
      getFileContentsIntData(argv[2]);
  Graph<int> intGraph(intFileContents, isDirected(argv[2]));
  cout << intGraph;
  cout << "Starting vertex: " << *intGraph.getStartVertex() << endl;
  cout << "Degree of vertex " << *intGraph.getData(3) << ": "
       << intGraph.getDegree(intGraph.getData(3)) << endl;
  cout << "Degree of vertex " << *intGraph.getData(4) << ": "
       << intGraph.getDegree(intGraph.getData(4)) << endl;

  vector<int *> testPath1;
  testPath1.push_back(intGraph.getData(4));
  testPath1.push_back(intGraph.getData(2));
  testPath1.push_back(intGraph.getData(0));
  testPath1.push_back(intGraph.getData(1));
  cout << "Printing path from vertex 10 to 4 to 1 to 2 (valid)" << endl;
  intGraph.printPath(testPath1);
  cout << "Path complete. Cost: " << intGraph.computeCost(testPath1) << endl;

  vector<int *> testPath2;
  testPath2.push_back(intGraph.getData(4));
  testPath2.push_back(intGraph.getData(2));
  testPath2.push_back(intGraph.getData(5));
  testPath2.push_back(intGraph.getData(0));
  cout << "Printing path from vertex 10 to 4 to 131 to 1 (invalid)" << endl;
  intGraph.printPath(testPath2);
  cout << "Path incomplete. Cost: " << intGraph.computeCost(testPath2) << endl;

  cout << "-------------TESTING WITH STRING GRAPH (INPUT 3)-------------"
       << endl;
  vector<tuple<string *, string *, double> > newStringFileContents =
      getFileContentsStringData(argv[3]);
  Graph<string> newStringGraph(newStringFileContents, isDirected(argv[3]));
  cout << newStringGraph;
  double pathLength = 0.0;
  vector<string *> shortestPathAF = newStringGraph.shortestPath(
      newStringGraph.getData(0), newStringGraph.getData(6), pathLength);
  return 0;
}
