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
  vector<vector<double> > adjMatrix; // stores weights of edges
  map<T *, int> newVertexIds; // stores vertex ids for row and col of adjMatrix
  bool directed;              // is the graph directed or nah
  int numVertices;            // rolling count of number of vertices in graph

  // helper function for dijkstra's algorithm
  // calculate the vertex with minimum distance and return the index of the
  // vertex that is unmarked
  // @param distances the distances to minimize
  // @param marked keeps track of which ids
  // @return int the index of the vertex with minimum distance
  int minDistanceId(vector<pair<double, T *> > distances, vector<bool> marked);

  // helper function for depth first printing of vertices
  // recursively traverse through graph and mark which vertices are visited
  // @param start the index to traverse from
  // @param &visited reference to vector that marks vertices that have already
  // been visited
  void dfTraverse(int start, vector<bool> &visited);

public:
  //--------------COMPLETED FUNCTIONS-----------
  // default constructor
  Graph();
  // create a graph given processed data from a file
  // @param edges vector of tuple in format <from, to, weight>
  // @param isDirected true if directed graph, false if not
  Graph(vector<tuple<T *, T *, double> > edges, bool isDirected);
  // destructor, frees pointers allocated in map
  ~Graph();
  // adds an edge to the graph between two vertices
  // **NOTE: this is a combination of addEdge and addWeight
  // from the prompt because every edge needs a weight
  // @param from the source vertex for the edge
  // @param to the destination vertex for the edge
  // @param weight the weight of the edge
  void addEdge(T *from, T *to, double weight);

  // @return vertex with id 0 (first added from the input file or addVertex)
  T *getStartVertex();

  // gets the vertex data given the id using reverse of map
  //**NOTE: this is analogous to findVertex() in prompt header file
  // @return vertex with index vertexId
  T *getData(int vertexId);

  // @return number of vertices (size of graph)
  int size();

  // gets the degree of a vertex by counting its neighbors
  // NOTE: for directed graph it returns outdegree
  // NOTE: degree += 2 for a self loop
  // @return degree of vertex
  int getDegree(T *vertex);

  // change the value of an existing vertex
  // @param oldVertexData to identify which vertex you want to change
  // @param newVertexData the new value of that vertex
  void setVertexData(T *oldVertexData, T *newVertexData);
  // @return adjacency matrix corresponding to the graph
  vector<vector<double> > getAdjMatrix();
  // @return true if directed, false if not
  bool isDirected();
  // add a vertex with no edges to the graph
  // @param data the value of the vertex
  void addVertex(T *data);
  // print a given path of edges and weights connecting vertices to cout
  // it does check if the path is valid or not
  // @param path the path of vertices that are in this graph
  void printPath(vector<T *> path);
  // compute cost of a given path
  // @param path the path of vertices that are in this graph
  // @return cost of path, -1.0 if path invalid
  double computeCost(vector<T *> path);

  // get the shortest path between two vertices
  // @param start source vertex
  // @param end destination vertex
  // @param &length to store the total length of this path
  // @return vector with shortest path from start vertex to end vertex
  vector<T *> shortestPath(T *start, T *end, double &length);
  // print vertices using depth first traversal to cout
  void dfPrint();
};
// implementation has to be included because its a template class
// tpp is standard for template implementation according to stackoverflow :)
#include "Graph.tpp"
#endif
