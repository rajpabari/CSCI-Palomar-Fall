#include "Graph.h"

template <typename T> void Graph<T>::addEdge(T *from, T *to, double weight) {
  // adds weight to adjacency matrix at mapped indices of from and to
  adjMatrix[newVertexIds[from]][newVertexIds[to]] = weight;
  // if it's an undirected graph, the edge goes from to to from as well
  if (!directed)
    adjMatrix[newVertexIds[to]][newVertexIds[from]] = weight;
}

template <typename T> Graph<T>::Graph() {
  // by default, there are no vertices and assume its undirected
  numVertices = 0;
  directed = false;
}

template <typename T> T *Graph<T>::getData(int vertexId) {
  // this is the inverse of the newVertexIds map
  // goal is to from id to data

  // for each pair in the map
  for (auto i : newVertexIds) {
    // if the id matches, its the corresponding pair
    // so return the corresponding vertex data
    if (i.second == vertexId)
      return i.first;
  }
  // if it's not found, return null
  return nullptr;
}

template <typename T>
Graph<T>::Graph(vector<tuple<T *, T *, double> > edges, bool isDirected) {
  // vertices starts at 0 because none have been added
  numVertices = 0;
  directed = isDirected;
  // add the vertices based on the ones that the edges refer to
  for (auto i : edges) {
    // if vertex is not in the map of existing vertices,
    // add vertex to map with a unique id and increment the numVertices
    if (newVertexIds.find(get<0>(i)) == newVertexIds.end())
      newVertexIds[get<0>(i)] = numVertices++;
    if (newVertexIds.find(get<1>(i)) == newVertexIds.end())
      newVertexIds[get<1>(i)] = numVertices++;
  }
  // initialize the adjacency matrix with no edges or weights
  for (int i = 0; i < newVertexIds.size(); i++) {
    vector<double> temp(newVertexIds.size(), 0.0);
    adjMatrix.push_back(temp);
  }
  // for each edge tuple, call addEdge function to add it to graph
  for (auto i : edges) {
    addEdge(get<0>(i), get<1>(i), get<2>(i));
  }
}

template <typename T> int Graph<T>::size() { return numVertices; }

template <typename T> T *Graph<T>::getStartVertex() { return getData(0); }

template <typename T> int Graph<T>::getDegree(T *vertex) {
  // grab the vertexId to make code more readable
  int vertexID = newVertexIds[vertex];
  // assume initially that no edges connect to this vertex
  int degree = 0;
  // for each row of adjacency matrix
  for (int i = 0; i < adjMatrix.size(); i++) {
    // check if there is an edge connected to this vertex
    if (adjMatrix[vertexID][i] != 0.0) {
      degree++;
      // if it's a self-loop, need to increment again
      if (i == vertexID)
        degree++;
    }
  }
  return degree;
}

template <typename T> Graph<T>::~Graph() {
  // free memory by deleting the pointers from the map
  for (auto i : newVertexIds) {
    delete i.first;
  }
}

template <typename T>
void Graph<T>::setVertexData(T *oldVertexData, T *newVertexData) {
  // save the id of the old vertex because we want to keep the id but not the
  // data
  int temp = newVertexIds[oldVertexData];
  // get rid of old vertex
  newVertexIds.erase(oldVertexData);
  // add new vertex with old id
  newVertexIds[newVertexData] = temp;
}

template <typename T> vector<vector<double> > Graph<T>::getAdjMatrix() {
  return adjMatrix;
}

template <typename T> bool Graph<T>::isDirected() { return directed; }

template <typename T> void Graph<T>::addVertex(T *data) {
  // add vertex to map with unique id and increment numVertices
  newVertexIds[data] = numVertices++;

  // need to expand n*n adjacency matrix to be size (n+1)*(n+1)
  // add a column of zeros to each row
  for (size_t i = 0; i < adjMatrix.size(); i++) {
    adjMatrix[i].push_back(0.0);
  }
  // add another row
  vector<double> temp(numVertices, 0.0);
  adjMatrix.push_back(temp);
}

template <typename T> double Graph<T>::computeCost(vector<T *> path) {
  double ans = 0.0; // cost starts at 0
  // for each vertex in path except for last vertex
  for (int i = 0; i < path.size() - 1; i++) {
    // if there's no edge from the current vertex to the next vertex, return -1
    if (adjMatrix[newVertexIds[path[i]]][newVertexIds[path[i + 1]]] == 0.0)
      return -1.0;
    // otherwise, add the weight to the running total of cost
    ans += adjMatrix[newVertexIds[path[i]]][newVertexIds[path[i + 1]]];
  }
  return ans;
}

template <typename T> void Graph<T>::printPath(vector<T *> path) {
  // for every vertex in path except last
  for (int i = 0; i < path.size() - 1; i++) {
    // if there's no edge from the current vertex to the next vertex,
    // print that in output and end the loop
    if (adjMatrix[newVertexIds[path[i]]][newVertexIds[path[i + 1]]] == 0.0) {
      cout << "No path from vertex " << *getData(newVertexIds[path[i]])
           << " to vertex " << *getData(newVertexIds[path[i + 1]]) << endl;
      break;
    }
    // otherwise, print from --> to and weight rounded to 3 decimals
    cout << "From vertex " << *getData(newVertexIds[path[i]]) << " to vertex "
         << *getData(newVertexIds[path[i + 1]]) << " with weight "
         << (round(adjMatrix[newVertexIds[path[i]]][newVertexIds[path[i + 1]]] *
                   1000.0) /
             1000.0)
         << endl;
  }
}

template <typename T>
int Graph<T>::minDistanceId(vector<pair<double, T *> > distances,
                            vector<bool> marked) {
  // minimum is assumed to be infinite initially
  double min = numeric_limits<double>::max();
  int minIndex;
  // for each vertex
  for (int i = 0; i < distances.size(); i++) {
    // if distance has not been finalized and the distance is less than the
    // current minimum
    if (!marked[i] && distances[i].first <= min) {
      // the current minimum is the first value of the pair
      min = distances[i].first;
      // the ID of the vertex is i
      minIndex = i;
    }
  }
  return minIndex;
}

template <typename T>
vector<T *> Graph<T>::shortestPath(T *start, T *end, double &length) {
  // initialize distances with infinite distance and null pointer to parent
  // format of pair is <distance, parent>
  vector<pair<double, T *> > distances(
      numVertices, make_pair(numeric_limits<double>::max(), nullptr));
  // stores whether the minimum distance is finalized or not, initialize to
  // false because no distances yet
  vector<bool> marked(numVertices, false);
  // the distance from start vertex to start vertex is 0.0
  distances[newVertexIds[start]].first = 0.0;

  // for each vertex except for the last
  for (int i = 0; i < numVertices - 1; i++) {
    // call helper function to get the id of the vertex that is minimized
    int minId = minDistanceId(distances, marked);
    // that is the minimum distance already, so mark it as true
    marked[minId] = true;
    // for each vertex
    for (int j = 0; j < numVertices; j++) {
      // 4 conditions must be met in order to update the distance of the vertex
      // 1) it's not already minimized already (not marked)
      // 2) the edge from current vertex to this one exists
      // 3) the distance minId is not infinite (if it is, dead path)
      // 4) new distance is less than the current distance of this vertex
      if (!marked[j] && adjMatrix[minId][j] != 0.0 &&
          distances[minId].first != numeric_limits<double>::max() &&
          distances[minId].first + adjMatrix[minId][j] <= distances[j].first) {
        // if all of those are true, update the distance
        distances[j].first = distances[minId].first + adjMatrix[minId][j];
        // and the parent vertex is the "from" vertex represented by minId
        distances[j].second = getData(minId);
      }
    }
  }
  // now the distance calculation is done, we need to backtrack to get the path
  int currentId = newVertexIds[end]; // start at the end
  vector<T *> path;
  // length is just the distance in the pair, set that reference parameter
  length = distances[currentId].first;
  // while the parent pointer is non-null
  while (distances[currentId].second) {
    // add the vertex corresponding to the index to the vector
    path.push_back(getData(currentId));
    // currentId is now the index of the parent of what currentId used to be
    currentId = newVertexIds[distances[currentId].second];
  }
  // also include the vertex with a null parent as that was the start vertex
  path.push_back(getData(currentId));
  // flip the order of the vector so it goes from start to end
  reverse(path.begin(), path.end());
  return path;
}

template <typename T> void Graph<T>::dfPrint() {
  cout << "Vertices using depth-first print: ";
  // create vector to keep track of which vertices we have printed and not
  vector<bool> visited(numVertices, false);
  // call recursive traversal function, starting at start index
  dfTraverse(newVertexIds[getStartVertex()], visited);
  cout << endl;
}

template <typename T>
void Graph<T>::dfTraverse(int start, vector<bool> &visited) {
  // we are visiting the vertex at start so mark it as true for visited
  visited[start] = true;
  // print out the value of this vertex to cout
  cout << *getData(start) << " ";

  // for each vertex
  for (size_t i = 0; i < numVertices; i++) {
    // if there is an edge between start and this vertex,
    // and the vertex hasn't been visited yet
    if (adjMatrix[start][i] != 0.0 && !visited[i]) {
      // begin traversal from that vertex
      dfTraverse(i, visited);
    }
  }
}

// Overload << operator to print graph to an output stream
// @param ostream &out the ostream to output graph to
// @param &printGraph the graph to print out
// @return ostream& an ostream with the graph printed and formatted on it
template <typename T> ostream &operator<<(ostream &out, Graph<T> &printGraph) {
  // print out the critical information about the graph
  out << "Vertices (" << printGraph.size() << " total): ";
  // get each vertex using getData
  for (int i = 0; i < printGraph.size(); i++) {
    out << *(printGraph.getData(i)) << " ";
  }
  // print each edges
  out << endl << "Edges (";
  // indicate if graph is directed or not
  if (printGraph.isDirected())
    out << "directed graph";
  else
    out << "undirected graph";
  out << "): " << endl;

  // get the adjacency matrix from public member function (this isn't a friend)
  vector<vector<double> > adjMatrix = printGraph.getAdjMatrix();
  // for each edge in the matrix
  for (int i = 0; i < adjMatrix.size(); i++) {
    for (int j = 0; j < adjMatrix[0].size(); j++) {
      // if the edge exists, print the from vertex, to vertex, and weight
      // rounded to 3 decimal places
      if (adjMatrix[i][j] != 0.0) {
        out << "From vertex " << *printGraph.getData(i) << " to vertex "
            << *printGraph.getData(j) << " with weight "
            << (round(adjMatrix[i][j] * 1000.0) / 1000.0) << endl;
      }
    }
  }
  return out;
}