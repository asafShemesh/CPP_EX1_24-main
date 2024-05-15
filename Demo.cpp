// 325362457   asaf0604@gmail.com
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
using ariel::Algorithms;

int main()
{
    ariel::Graph g;

    // Example 1: 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);

    g.printGraph();                                     // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms().isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms().shortestPath(g, 0, 2) << endl; // Should print: "0->1->2".
    cout << Algorithms().isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms().isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}".

    // Example 2: 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);

    g.printGraph();                                     // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms().isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms().shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms().isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    cout << Algorithms().isBipartite(g) << endl;        // Should print: "0" (false).

    // Example 3: 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);

    g.printGraph();                                     // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms().isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms().shortestPath(g, 0, 4) << endl; // Should print: "0->1->2->3->4".
    cout << Algorithms().isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms().isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}".

    // Example 4: 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4);
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }

    // Example 5: Graph with 6 vertices and 30 edges
    vector<vector<int>> graph5 = {
        {0, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 0}};
    g.loadGraph(graph5);

    g.printGraph();                              // Should print: "Graph with 6 vertices and 30 edges."
    cout << Algorithms().isConnected(g) << endl; // Should print: "1" (true).

    // Example 6: Graph with 4 vertices and 8 edges .
    vector<vector<int>> graph6 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}};
    g.loadGraph(graph6);

    g.printGraph();                                  // Should print: "Graph with 4 vertices and 8 edges."
    cout << Algorithms().isContainsCycle(g) << endl; // Should print: "The cycle is: 0->1->2->3->0"
    cout << Algorithms().isConnected(g) << endl;     // Should print: "1" (true).

    // Example 7: Graph with 7 vertices and no edges.
    vector<vector<int>> graph7 = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph7);

    g.printGraph();                              // Should print: "Graph with 7 vertices and 0 edges."
    cout << Algorithms().isConnected(g) << endl; // Should print: "0" (false).

    // Example 8: Graph with 1 vertex and no edges.
    vector<vector<int>> graph8 = {{0}};
    g.loadGraph(graph8);

    g.printGraph();                              // Should print: "Graph with 1 vertex and 0 edges."
    cout << Algorithms().isConnected(g) << endl; // Should print: "1" (true).

    // Example 9: Graph with 3 vertices and no edges.
    vector<vector<int>> graph9 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph9);

    g.printGraph();                              // Should print: "Graph with 3 vertices and 0 edges."
    cout << Algorithms().isConnected(g) << endl; // Should print: "0" (false).

    // Example 10: Graph with self-loop.
    vector<vector<int>> graph10 = {{1}};
    g.loadGraph(graph10);

    g.printGraph();                              // Should print: "Graph with 1 vertex and 1 edges."
    cout << Algorithms().isConnected(g) << endl; // Should print: "1" (true).
}