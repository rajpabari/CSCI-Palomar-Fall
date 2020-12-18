#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <map>
#include <random>
#include <vector>
using namespace std;

template <typename S>

class Vertex {
public:
  Vertex(S inData, int vertexId);
  Vertex(S inData);
  S getData() const;
  map<int, double> getWeights();
  vector<Vertex *> getEdges();
  void setData(S inData);
  void addEdge(Vertex *toVertex, double edgeWeight);
  void addEdge(Vertex *toVertex);
  void setWeight(int id, double edgeWeight);
  int getDegree() const;

private:
  S data;
  int id;
  map<int, double> weights; // int ID, double weight
  vector<Vertex *> edges;
  int degree;
};

#endif