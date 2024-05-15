// 325362457   asaf0604@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <vector>

TEST_CASE("Test isConnected")
{
    ariel::Graph g;

    SUBCASE("Connected Graph")
    {
        std::vector<std::vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph1);
        CHECK(ariel::Algorithms().isConnected(g) == 1);
    }

    SUBCASE("Disconnected Graphs")
    {
        std::vector<std::vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
        g.loadGraph(graph2);
        CHECK(ariel::Algorithms().isConnected(g) == 0);

        std::vector<std::vector<int>> graph3 = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 0}};
        g.loadGraph(graph3);
        CHECK(ariel::Algorithms().isConnected(g) == 0);
    }

    SUBCASE("Fully Connected Graph")
    {
        std::vector<std::vector<int>> graph4 = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}};
        g.loadGraph(graph4);
        CHECK(ariel::Algorithms().isConnected(g) == 1);
    }
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;

    SUBCASE("Path Exists")
    {
        std::vector<std::vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph1);
        CHECK(ariel::Algorithms().shortestPath(g, 0, 2) == "0->1->2");

        std::vector<std::vector<int>> graph4 = {
            {0, 3, 0, 0, 0},
            {3, 0, 1, 0, 0},
            {0, 1, 0, 2, 0},
            {0, 0, 2, 0, 4},
            {0, 0, 0, 4, 0}};
        g.loadGraph(graph4);
        CHECK(ariel::Algorithms().shortestPath(g, 0, 4) == "0->1->2->3->4");
    }

    SUBCASE("No Path Available")
    {
        std::vector<std::vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
        g.loadGraph(graph2);
        CHECK(ariel::Algorithms().shortestPath(g, 0, 4) == "-1");

        std::vector<std::vector<int>> graph3 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
        g.loadGraph(graph3);
        CHECK(ariel::Algorithms().shortestPath(g, 0, 2) == "-1");
    }
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;

    SUBCASE("No Cycle")
    {
        std::vector<std::vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph1);
        CHECK(ariel::Algorithms().isContainsCycle(g) == 0);
    }

    SUBCASE("Cycle Exists")
    {
        std::vector<std::vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
        g.loadGraph(graph2);
        CHECK(ariel::Algorithms().isContainsCycle(g) == 1);

        std::vector<std::vector<int>> graph3 = {
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {1, 0, 1, 0}};
        g.loadGraph(graph3);
        CHECK(ariel::Algorithms().isContainsCycle(g) == 1);
    }
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;

    SUBCASE("Bipartite Graphs")
    {
        std::vector<std::vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph1);
        CHECK(ariel::Algorithms().isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

        std::vector<std::vector<int>> graph3 = {
            {0, 1, 0, 0, 0},
            {1, 0, 3, 0, 0},
            {0, 3, 0, 4, 0},
            {0, 0, 4, 0, 5},
            {0, 0, 0, 5, 0}};
        g.loadGraph(graph3);
        CHECK(ariel::Algorithms().isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

        std::vector<std::vector<int>> graph6 = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
        g.loadGraph(graph6);
        CHECK(ariel::Algorithms().isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
    }

    SUBCASE("Non-Bipartite Graphs")
    {
        std::vector<std::vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
        g.loadGraph(graph2);
        CHECK(ariel::Algorithms().isBipartite(g) == "0");

        std::vector<std::vector<int>> graph4 = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}};
        g.loadGraph(graph4);
        CHECK(ariel::Algorithms().isBipartite(g) == "0");
    }
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;

    SUBCASE("Invalid Graph Structure")
    {
        std::vector<std::vector<int>> graph = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 0, 4, 0},
            {0, 0, 0, 5}};
        CHECK_THROWS(g.loadGraph(graph));
    }
}
TEST_CASE("Test additional functionality")
{
    ariel::Graph g;

    SUBCASE("Graph with One Node")
    {
        std::vector<std::vector<int>> graph = {{0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms().isConnected(g) == 1);
        CHECK(ariel::Algorithms().shortestPath(g, 0, 0) == "0");
        CHECK(ariel::Algorithms().isContainsCycle(g) == 0);
        CHECK(ariel::Algorithms().isBipartite(g) == "The graph is bipartite: A={0}, B={}");
    }

    SUBCASE("Graph with Two Disconnected Nodes")
    {
        std::vector<std::vector<int>> graph = {{0, 0}, {0, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms().isConnected(g) == 0);
        CHECK(ariel::Algorithms().shortestPath(g, 0, 1) == "-1");
        CHECK(ariel::Algorithms().isContainsCycle(g) == 0);
    }

    SUBCASE("Graph with Self-Loop")
    {
        std::vector<std::vector<int>> graph = {{1}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms().isConnected(g) == 1);
        CHECK(ariel::Algorithms().shortestPath(g, 0, 0) == "0");
    }
}