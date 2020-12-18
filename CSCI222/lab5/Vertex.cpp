#include "Vertex.h"

template <typename S> Vertex<S>::Vertex(S inData, int vertexId) {
  data = inData;
  degree = 0;
  id = vertexId;
}

template <typename S> Vertex<S>::Vertex(S inData) {
  srand(time(0));
  Vertex(inData, rand() % 1000);
}

template <typename S> S Vertex<S>::getData() const { return data; }

template <typename S> map<int, double> Vertex<S>::getWeights() {
  return weights;
}

template <typename S> vector<Vertex<S> *> Vertex<S>::getEdges() {
  return edges;
}