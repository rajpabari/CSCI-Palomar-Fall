#include "Graph.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

// Extra features added on top of the requirements:
// 1) directed/undirected graph support
// 2) destructor so no memory leak :)
// 3) overloaded the << operator to print graph

// Hi professor, just a note that I decided to do file processing in this file
// instead of passing string filename into the constructor and processing there

// this file is so long just because of the processing and testing
// each and every member function :)

// prepares the contents of the file located at filePath for graph of int
//@param string filePath the path to the file
//@return the contents of the file in a vector of tuples
vector<tuple<int *, int *, double> > getFileContentsIntData(string filePath) {
  vector<tuple<int *, int *, double> > data; // to store input data from file
  ifstream infile;
  infile.open(filePath); // open the filename supplied
  string line;
  string word;
  int numWordsRead;
  // the purpose of this map is to ensure that the same pointers
  // are used to point to the same value
  // for instance, if vertex apple is read 3x, we dont want
  // 3 separate pointers to apple in 3 different places
  // because they should all be pointing to the same vertex
  map<int, int *> uniqueData;

  // while there are lines to read in the file
  while (getline(infile, line)) {
    // if its the first line of the file ignore it for vector making purposes
    if (line == "directed" || line == "undirected")
      continue;
    numWordsRead = 0; // words read on the line so far
    tuple<int *, int *, double> current;
    // read each word of the line using an input string stream
    istringstream iss(line, istringstream::in);
    // while there's a word to read on this line
    while (iss >> word) {
      // if it's the first word
      if (numWordsRead == 0) {
        // if the int is in the unique data map already...
        // stoi is string to int
        if (uniqueData.find(stoi(word)) != uniqueData.end()) {
          // just save the pointer that was already generated and move on
          get<0>(current) = uniqueData[stoi(word)];
        } else {
          // if it's not in the unique data map,
          // create a new pointer to the integer
          int *newInt = new int;
          *newInt = stoi(word);
          // store it in tuple
          get<0>(current) = newInt;
          // add it to the map so future pointers to this value are the same
          uniqueData[stoi(word)] = newInt;
        }
      }
      // same as if its the first word but for the second word
      // note: have to use constants (0, 1, 2) with the get function on tuple
      // otherwise i would have used a for loop :)
      else if (numWordsRead == 1) {
        if (uniqueData.find(stoi(word)) != uniqueData.end()) {
          get<1>(current) = uniqueData[stoi(word)];
        } else {
          int *newInt = new int;
          *newInt = stoi(word);
          get<1>(current) = newInt;
          uniqueData[stoi(word)] = newInt;
        }
      }
      // double is not pointer related so it's simpler
      else {
        // just store the weight in the tuple
        // stod is string to double
        double weight = stod(word);
        get<2>(current) = weight;
      }
      // we just read a word, so increment numWordsRead
      numWordsRead++;
    }
    // push each processed tuple to the end of the vector
    data.push_back(current);
  }
  // close file
  infile.close();
  // return our processed vector
  return data;
}

// prepares the contents of the file located at filePath for graph of string
//@param string filePath the path to the file
//@return the contents of the file in a vector of tuples
vector<tuple<string *, string *, double> >
getFileContentsStringData(string filePath) {
  // NOTE: NOT COMMENTING THIS because it's mostly the same as the int one
  // I didn't want to template stuff in the testing class
  // so i just copy/pasted method and changed the data type
  // the only other difference is the string pointer syntax
  // and we dont have to use stoi() in this one
  vector<tuple<string *, string *, double> > data;
  ifstream infile;
  infile.open(filePath);
  string line;
  string word;
  int numWordsRead;
  map<string, string *> uniqueData;

  while (getline(infile, line)) {
    numWordsRead = 0;
    if (line == "directed" || line == "undirected")
      continue;
    tuple<string *, string *, double> current;
    istringstream iss(line, istringstream::in);
    while (iss >> word) {
      if (numWordsRead == 0) {
        // this is really the only difference
        if (uniqueData.find(word) != uniqueData.end()) {
          get<0>(current) = uniqueData[word];
        } else {
          // the syntax of this
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
    data.push_back(current);
  }
  infile.close();
  return data;
}

// tells if the graph is directed or undirected based on input file first line
// @param filePath the path to the input file
// @return true if directed graph, false if not
bool isDirected(string filePath) {
  // open the file
  ifstream infile;
  infile.open(filePath);
  string line;
  // store the first line to line
  getline(infile, line);
  infile.close();

  // if that line was "directed", we return true. otherwise false
  if (line == "directed")
    return true;
  else
    return false;
}

// Display usage information to cout
void usage() {
  cout << "Input path to graph input file 1, 2, and 3 in command line" << endl;
  cout << "Example: g++ GraphRunner.cpp ./CSCI222/lab5/GraphInput1.txt "
          "./CSCI222/lab5/GraphInput2.txt ./CSCI222/lab5/GraphInput3.txt"
       << endl;
  cout << "note: file format is as follows"
          "line 1: \"directed\" or \"undirected\" graph\n\nrest of lines "
          "define "
          "edges in format: vertexFrom vertexTo weight\nexample: A B "
          "3.5\nexample: hotdog burger 5.3\nexample: 4 2 1.4"
       << endl;
}

int main(int argc, char const *argv[]) {
  // if there isn't 3 arguments (argv[0] is filename)
  if (argc != 4) {
    usage();  // display usage info
    return 0; // exit program
  }

  // the following driver code just serves to test the graph member functions
  // with different inputs

  cout << "-------------TESTING WITH STRING GRAPH (INPUT 1)-------------"
       << endl;
  vector<tuple<string *, string *, double> > stringFileContents =
      getFileContentsStringData(argv[1]);
  // use graph overloaded constructor
  Graph<string> stringGraph(stringFileContents, isDirected(argv[1]));
  cout << "ORIGINAL STRING GRAPH:" << endl;
  // use overloaded operator to print out the graph
  cout << stringGraph;

  // test setter function
  string *toReplace = new string("lettuce");
  cout << "Replacing vertex " << *stringGraph.getData(0) << " with "
       << *toReplace << endl;
  stringGraph.setVertexData(stringGraph.getData(0), toReplace);

  // test adding vertex and edges
  string *toAdd = new string("zucchini");
  cout << "Adding vertex " << *toAdd << endl;
  stringGraph.addVertex(toAdd);
  cout << "Adding edge from " << *toAdd << " to " << *toReplace
       << " with weight 2.2" << endl;
  stringGraph.addEdge(toAdd, toReplace, 2.2);
  cout << "Adding edge from " << *toAdd << " to " << *stringGraph.getData(2)
       << " with weight 4.9" << endl;
  stringGraph.addEdge(toAdd, stringGraph.getData(2), 4.9);

  // print it out again
  cout << "MODIFIED STRING GRAPH:" << endl;
  cout << stringGraph;

  cout << "-------------TESTING WITH INT GRAPH (INPUT 2)-------------" << endl;

  // new input so read the contents again and construct new graph
  vector<tuple<int *, int *, double> > intFileContents =
      getFileContentsIntData(argv[2]);
  Graph<int> intGraph(intFileContents, isDirected(argv[2]));
  cout << intGraph;
  // test start vertex function
  cout << "Starting vertex: " << *intGraph.getStartVertex() << endl;
  // test degree (+2 for self-loop)
  cout << "Degree of vertex " << *intGraph.getData(3) << ": "
       << intGraph.getDegree(intGraph.getData(3)) << endl;
  cout << "Degree of vertex " << *intGraph.getData(4) << ": "
       << intGraph.getDegree(intGraph.getData(4)) << endl;

  // test printing a valid path and the cost associated
  vector<int *> testPath1;
  testPath1.push_back(intGraph.getData(4));
  testPath1.push_back(intGraph.getData(2));
  testPath1.push_back(intGraph.getData(0));
  testPath1.push_back(intGraph.getData(1));
  cout << "Printing path from vertex 10 to 4 to 1 to 2 (valid)" << endl;
  intGraph.printPath(testPath1);
  cout << "Path complete. Cost: " << intGraph.computeCost(testPath1) << endl;

  // test printing an invalid path and the cost associated
  vector<int *> testPath2;
  testPath2.push_back(intGraph.getData(4));
  testPath2.push_back(intGraph.getData(2));
  testPath2.push_back(intGraph.getData(5));
  testPath2.push_back(intGraph.getData(0));
  cout << "Printing path from vertex 10 to 4 to 131 to 1 (invalid)" << endl;
  intGraph.printPath(testPath2);
  cout << "Path incomplete. Cost: " << intGraph.computeCost(testPath2) << endl;

  cout << "-------------TESTING WITH STRING GRAPH (INPUT 3 FROM LECTURE "
          "SLIDES)-------------"
       << endl;
  // this is a test of DFS and dijkstra with the input from the lecture slides
  vector<tuple<string *, string *, double> > newStringFileContents =
      getFileContentsStringData(argv[3]);
  Graph<string> newStringGraph(newStringFileContents, isDirected(argv[3]));
  cout << newStringGraph;
  // test out the depth first print
  newStringGraph.dfPrint();
  // find shortest path from A to F like in the lectures and cost associated
  double pathCost = 0.0;
  cout << "Shortest path from vertex A to F:" << endl;
  vector<string *> shortestPathAF = newStringGraph.shortestPath(
      newStringGraph.getData(0), newStringGraph.getData(5), pathCost);
  newStringGraph.printPath(shortestPathAF);
  cout << "Total cost of path: " << pathCost << endl;

  // done! happy holidays :)
  return 0;
}
