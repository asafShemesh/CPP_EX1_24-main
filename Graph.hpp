// 325362457   asaf0604@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept>

namespace ariel
{
    class Graph
    {
    public:
        Graph();

        Graph(const std::vector<std::vector<int>> &matrix);

        void loadGraph(const std::vector<std::vector<int>> &matrix);

        void printGraph() const;

        const std::vector<std::vector<int>> &getAdjacencyMatrix() const;

    private:
        std::vector<std::vector<int>> adjacencyMatrix;
    };
}

#endif
