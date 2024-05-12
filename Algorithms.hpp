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
        std ::string shortestPath(Graph g, int s, int e);

        int isContainsCycle(Graph &g);

        std ::string isBipartite(Graph g);
        void negativeCycle(Graph &g);

        bool hasLoopbacks(Graph g);


    private:
        int minDistance(std::vector<int> distances, std::vector<bool> visited);
    };

}

#endif