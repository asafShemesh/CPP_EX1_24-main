// 325362457   asaf0604@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"
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
    private:
        bool hasLoopbacks(Graph g);
    };

}

#endif