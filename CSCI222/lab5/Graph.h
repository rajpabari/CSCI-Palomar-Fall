#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <typename T>

class Graph {
private:
  vector<vector<pair<T, int> > > adjMatrix;
  map<int, int> newVertexIds;

public:
  Graph(vector<string> inputFile);
  getDegree(int vertexId);
};

#endif
