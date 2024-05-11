// 325362457   asaf0604@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <queue>
namespace ariel
{

    class Algorithms
    {
    public:
        int isConnected(Graph &g);
        int shortestPath(Graph &g, size_t start, size_t end);
        int isContainsCycle(Graph &g);
        int isBipartite(Graph &g);
        void negativeCycle(Graph &g);

    private:
        bool isCyclicUtil(Graph &g, size_t v, std::vector<bool> &visited, std::vector<bool> &recStack);
        bool isBipartiteUtil(Graph &g, size_t v, std::vector<int> &color);
    };

}

#endif