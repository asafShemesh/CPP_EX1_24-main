    #include "Graph.hpp"
    #include <iostream>

    namespace ariel {
        void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
            size_t size = matrix.size();
            for (const auto& row : matrix) {
                if (row.size() != size) {
                    throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
                }
            }

            adjacencyMatrix = matrix;
        }

        void Graph::printGraph() const {
            std::cout << "Graph with " << adjacencyMatrix.size() << " vertices and " << std::endl;
            int edges = 0;
            for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
                for (size_t j = i + 1; j < adjacencyMatrix[i].size(); ++j) {
                    if (adjacencyMatrix[i][j] != 0) {
                        std::cout << i << " - " << j << ": " << adjacencyMatrix[i][j] << std::endl;
                        edges++;
                    }
                }
            }
            std::cout << edges << " edges." << std::endl;
        }
    }
