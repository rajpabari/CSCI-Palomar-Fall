#include "Graph.h"

template <typename T> void Graph<T>::addEdge(T *from, T *to, double weight) {
  adjMatrix[newVertexIds[from]][newVertexIds[to]] = weight;
  if (!directed)
    adjMatrix[newVertexIds[to]][newVertexIds[from]] = weight;
}

template <typename T> Graph<T>::Graph() {
  numVertices = 0;
  directed = false;
}

template <typename T> T *Graph<T>::getData(int vertexId) {
  for (auto i : newVertexIds) {
    if (i.second == vertexId)
      return i.first;
  }
  return nullptr;
}

template <typename T>
Graph<T>::Graph(vector<tuple<T *, T *, double> > edges, bool isDirected) {
  numVertices = 0;
  directed = isDirected;
  for (auto i : edges) {
    if (newVertexIds.find(get<0>(i)) == newVertexIds.end())
      newVertexIds[get<0>(i)] = numVertices++;
    if (newVertexIds.find(get<1>(i)) == newVertexIds.end())
      newVertexIds[get<1>(i)] = numVertices++;
  }
  for (int i = 0; i < newVertexIds.size(); i++) {
    vector<double> temp(newVertexIds.size(), 0.0);
    adjMatrix.push_back(temp);
  }
  for (auto i : edges) {
    addEdge(get<0>(i), get<1>(i), get<2>(i));
  }
}

template <typename T> int Graph<T>::size() { return numVertices; }

template <typename T> T *Graph<T>::getStartVertex() { return getData(0); }

template <typename T> int Graph<T>::getDegree(T *vertex) {
  int vertexID = newVertexIds[vertex];
  int degree = 0;
  for (int i = 0; i < adjMatrix.size(); i++) {
    if (adjMatrix[vertexID][i] != 0.0) {
      degree++;
      if (i == vertexID)
        degree++;
    }
  }
  return degree;
}

template <typename T> Graph<T>::~Graph() {
  for (auto i : newVertexIds) {
    delete i.first;
  }
}

template <typename T>
void Graph<T>::replaceVertexData(T *oldVertexData, T *newVertexData) {
  int temp = newVertexIds[oldVertexData];
  newVertexIds.erase(oldVertexData);
  newVertexIds[newVertexData] = temp;
}

template <typename T> vector<vector<double> > Graph<T>::getAdjMatrix() {
  return adjMatrix;
}

template <typename T> bool Graph<T>::isDirected() { return directed; }

template <typename T> void Graph<T>::addVertex(T *data) {
  newVertexIds[data] = numVertices++;
  for (size_t i = 0; i < adjMatrix.size(); i++) {
    adjMatrix[i].push_back(0.0);
  }
  vector<double> temp(numVertices, 0.0);
  adjMatrix.push_back(temp);
}

template <typename T> double Graph<T>::computeCost(vector<T *> path) {
  double ans = 0.0;
  for (int i = 0; i < path.size() - 1; i++) {
    if (adjMatrix[newVertexIds[path[i]]][newVertexIds[path[i + 1]]] == 0.0)
      return -1.0;
    ans += adjMatrix[newVertexIds[path[i]]][newVertexIds[path[i + 1]]];
  }
  return ans;
}

template <typename T> void Graph<T>::printPath(vector<T *> path) {
  for (int i = 0; i < path.size() - 1; i++) {
    if (adjMatrix[newVertexIds[path[i]]][newVertexIds[path[i + 1]]] == 0.0) {
      cout << "No path from vertex " << *getData(newVertexIds[path[i]])
           << " to vertex " << *getData(newVertexIds[path[i + 1]]) << endl;
      break;
    }
    cout << "From vertex " << *getData(newVertexIds[path[i]]) << " to vertex "
         << *getData(newVertexIds[path[i + 1]]) << " with weight "
         << (round(adjMatrix[newVertexIds[path[i]]][newVertexIds[path[i + 1]]] *
                   1000.0) /
             1000.0)
         << endl;
  }
}

template <typename T>
vector<T *> Graph<T>::shortestPath(T *start, T *end, double &length) {
  vector<pair<double, T *> > distances(
      numVertices, make_pair(numeric_limits<double>::max(), nullptr));
  vector<bool> marked(numVertices, false);
  int currentId = newVertexIds[start];
  distances[currentId].first = 0.0;
  marked[currentId] = true;
  int endId = newVertexIds[end];
  double totalDistance = 0.0;

  T *currentVertex = start;
  double minDistance;
  int minId;
  while (find(marked.begin(), marked.end(), false) != marked.end()) {
    minDistance = numeric_limits<double>::max();
    currentId = newVertexIds[currentVertex];
    for (int i = 0; i < adjMatrix.size(); i++) {
      if (adjMatrix[currentId][i] != 0.0 && !marked[i]) {
        if (adjMatrix[currentId][i] < minDistance) {
          minDistance = adjMatrix[currentId][i];
          minId = i;
        }
      }
    }
    currentVertex = getData(minId);
    currentVertex.first = marked[minId] = true;
    for (int i = 0; i < adjMatrix.size(); i++) {
      if (adjMatrix[minId][i] != 0.0 && !marked[i]) {
        double dist = distances[minId].first + adjMatrix[minId][i];
        if (dist < distances[i].first) {
          distances[i].first = dist;
          distances[i].second = currentVertex;
        }
      }
    }
  }
  cout << "happiness" << endl;
  vector<T *> ans;
  return ans;
}

// Overload << operator to print graph to an output stream
// @param ostream &out the ostream to output graph to
// @param &printGraph the graph to print out
// @return ostream& an ostream with the graph printed and formatted on it
template <typename T> ostream &operator<<(ostream &out, Graph<T> &printGraph) {

  out << "Vertices (" << printGraph.size() << " total): ";
  for (int i = 0; i < printGraph.size(); i++) {
    out << *(printGraph.getData(i)) << " ";
  }
  out << endl << "Edges (";
  if (printGraph.isDirected())
    out << "directed graph";
  else
    out << "undirected graph";
  out << "): " << endl;
  vector<vector<double> > adjMatrix = printGraph.getAdjMatrix();
  for (int i = 0; i < adjMatrix.size(); i++) {
    for (int j = 0; j < adjMatrix[0].size(); j++) {
      if (adjMatrix[i][j] != 0.0) {
        out << "From vertex " << *printGraph.getData(i) << " to vertex "
            << *printGraph.getData(j) << " with weight "
            << (round(adjMatrix[i][j] * 1000.0) / 1000.0) << endl;
      }
    }
  }
  return out;
}