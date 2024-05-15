// 325362457   asaf0604@gmail.com
#include "Graph.hpp"
#include <iostream>

namespace ariel
{
    Graph::Graph() {}

    void Graph::loadGraph(const std::vector<std::vector<int>> &matrix)
    {
        size_t size = matrix.size();
        for (const auto &row : matrix)
        {
            if (row.size() != size)
            {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }

        adjacencyMatrix = matrix;
    }

    void Graph::printGraph() const
    {
        std::cout << "Graph with " << adjacencyMatrix.size() << " vertices and ";
        int edges = getNumEdges();
        std::cout << edges << " edges." << std::endl;
    }

    const std::vector<std::vector<int>> &Graph::getAdjacencyMatrix() const
    {
        return adjacencyMatrix;
    }

    size_t Graph::getNumVertices() const
    {
        return adjacencyMatrix.size();
    }

    size_t Graph::getNumEdges() const
    {
        size_t edges = 0;
        for (const auto &row : adjacencyMatrix)
        {
            for (int weight : row)
            {
                if (weight != 0)
                {
                    edges++;
                }
            }
        }
        return edges;
    }

    int Graph::getValue(size_t row, size_t col) const
    {
        if (row >= adjacencyMatrix.size() || col >= adjacencyMatrix.size())
        {
            throw std::out_of_range("Invalid indices.");
        }
        return adjacencyMatrix[row][col];
    }

}