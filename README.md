# Task 1 - Graphs (Classes and Namespaces)
325362457 asaf0604@gmail.com

This project implements various graph algorithms and utilities in C++. It includes the following algorithms:

## Algorithms

- `isConnected(Graph &g)`: Checks if the graph is connected by performing a depth-first search (DFS) and verifying if all vertices are visited.
  
- `shortestPath(Graph g, int s, int e)`: Finds the shortest path on the graph from the start vertex to the end vertex using a variant of the Bellman-Ford algorithm.
  
- `isContainsCycle(Graph &g)`: Determines if the graph contains any cycles using DFS and back-edge detection.
  
- `negativeCycle(Graph &g)`: Checks for the presence of a negative cycle in the graph using the Bellman-Ford algorithm.
  
- `isBipartite(Graph g)`: Determines if the graph is bipartite by attempting to 2-color the graph.

## Graph

The `Graph` class contains functionalities to represent and work with graphs. These include:

- `loadGraph(const std::vector<std::vector<int>> &matrix)`: Loads the graph from the given adjacency matrix.
  
- `printGraph() const`: Prints information about the graph, including the number of vertices and edges.
  
- `getAdjacencyMatrix() const`: Returns the adjacency matrix of the graph.
  
- `getNumVertices() const`: Returns the number of vertices in the graph.
  
- `getNumEdges() const`: Returns the number of edges in the graph.
  
- `getValue(size_t row, size_t col) const`: Returns the value at the specified position in the adjacency matrix.

## Makefile

To compile the program, run `make` and then execute `./demo` or `./test` accordingly.
