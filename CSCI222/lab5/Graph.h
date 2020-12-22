#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
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
  T *getData(int vertexId);
  // traverse map and find pointer to corresponding data
  int numVertices;

public:
  Graph();
  Graph(vector<tuple<T *, T *, double> > edges, bool isDirected);
  void addEdge(T *from, T *to, double weight);
  // add edge from --> to with weight weight

  /*int getDegree(T *vertex);
  // map T to int, count how many neighbors it has, +2 for self loop
  void replaceVertexData(T *oldVertexData, T *newVertexData);
  // change the map
  void addVertex(T *data);
  // add to the map

  T *getStartVertex();
  // return vertex with id 0
  void dftraverse();
  // depth first traversal
  vector<T *> shortestPath(T *start, T *end, double &length);
  // return shortest path and put length of path in length param
  double computeCost(vector<T *> path);
  // compute cost of a given path

  void printPath(vector<T *> path);
  // print to cout
  T getVertex(int id);*/
};

#include "Graph.tpp"
#endif
