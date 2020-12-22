#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

template <class T>

class Graph {
private:
  vector<vector<double> > adjMatrix; // stores weights
  map<T *, int> newVertexIds; // stores vertex ids for row and col of adjMatrix
  bool directed;              // is directed or nah
  int numVertices;
  int minDistanceId(vector<pair<double, T *> > distances, vector<bool> marked);
  void dfTraverse(int start, vector<bool> &visited);

public:
  //--------------COMPLETED FUNCTIONS-----------
  Graph();
  Graph(vector<tuple<T *, T *, double> > edges, bool isDirected);
  ~Graph();
  void addEdge(
      T *from, T *to,
      double weight); // **NOTE: this is a combination of addEdge and addWeight
                      // from the prompt because every edge needs a weight
  // add edge from --> to with weight weight
  T *getStartVertex();
  // return vertex with id 0
  T *getData(int vertexId); //**NOTE: this is analogous to findVertex() in
                            // prompt Graph.h
  // traverse map and find pointer to corresponding data
  int size();
  // return number of vertices
  int getDegree(T *vertex);
  // map T to int, count how many neighbors it has, +2 for self loop
  // NOTE for directed graph it returns outdegree
  void setVertexData(T *oldVertexData, T *newVertexData);
  // change the map
  vector<vector<double> > getAdjMatrix();
  // return adjacency matrix
  bool isDirected();
  // return true if directed, false if not
  void addVertex(T *data);
  // add to the map
  void printPath(vector<T *> path);
  // print to cout
  double computeCost(vector<T *> path);
  // compute cost of a given path
  vector<T *> shortestPath(T *start, T *end, double &length);
  // return shortest path and put length of path in length param
  void dfPrint();
  // print using depth first traversal
};

#include "Graph.tpp"
#endif
