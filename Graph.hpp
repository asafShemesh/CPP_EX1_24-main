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

        void loadGraph(const std::vector<std::vector<int>> &matrix);
        void printGraph() const;
        const std::vector<std::vector<int>> &getAdjacencyMatrix() const;
        size_t getNumVertices() const;
        size_t getNumEdges() const;
        int getValue(size_t row, size_t col) const;
        std::vector<std::vector<int>> adjacencyMatrix;
    };
}

#endif
