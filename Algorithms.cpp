#include "Algorithms.hpp"

namespace ariel {

int Algorithms::isConnected(Graph& g) {
    const auto& adjacencyMatrix = g.getAdjacencyMatrix();
    std::vector<bool> visited(adjacencyMatrix.size(), false);
    std::queue<size_t> q; // Use size_t for index type
    q.push(0); // Start with any vertex
    visited[0] = true;

    while (!q.empty()) {
        size_t current = q.front(); // Use size_t for index type
        q.pop();
        for (size_t i = 0; i < adjacencyMatrix[current].size(); ++i) { // Use size_t for index type
            if (adjacencyMatrix[current][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    for (bool v : visited) {
        if (!v) return 0;
    }

    return 1;
}

int Algorithms::shortestPath(Graph& g, size_t start, size_t end) { // Update parameter types to size_t
    std::vector<int> distances(g.getAdjacencyMatrix().size(), -1);
    std::queue<size_t> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty()) {
        size_t current = q.front();
        q.pop();
        for (size_t i = 0; i < g.getAdjacencyMatrix()[current].size(); ++i) {
            if (g.getAdjacencyMatrix()[current][i] && distances[i] == -1) {
                q.push(i);
                distances[i] = distances[current] + 1;
            }
        }
    }

    return distances[end];
}

bool Algorithms::isCyclicUtil(Graph& g, size_t v, std::vector<bool>& visited, std::vector<bool>& recStack) { // Use size_t for index type
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        const auto& adjacencyMatrix = g.getAdjacencyMatrix();
        for (size_t i = 0; i < adjacencyMatrix[v].size(); ++i) { // Use size_t for index type
            if (adjacencyMatrix[v][i]) {
                if (!visited[i] && isCyclicUtil(g, i, visited, recStack)) {
                    return true;
                } else if (recStack[i]) {
                    return true;
                }
            }
        }
    }
    recStack[v] = false;
    return false;
}

int Algorithms::isContainsCycle(Graph& g) {
    const auto& adjacencyMatrix = g.getAdjacencyMatrix();
    std::vector<bool> visited(adjacencyMatrix.size(), false);
    std::vector<bool> recStack(adjacencyMatrix.size(), false);

    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) { // Use size_t for index type
        if (isCyclicUtil(g, i, visited, recStack)) {
            return 1;
        }
    }

    return 0;
}

bool Algorithms::isBipartiteUtil(Graph& g, size_t v, std::vector<int>& color) { // Use size_t for index type
    const auto& adjacencyMatrix = g.getAdjacencyMatrix();
    std::queue<size_t> q; // Use size_t for index type
    q.push(v);
    color[v] = 1;

    while (!q.empty()) {
        size_t current = q.front(); // Use size_t for index type
        q.pop();
        for (size_t i = 0; i < adjacencyMatrix[current].size(); ++i) { // Use size_t for index type
            if (adjacencyMatrix[current][i] && color[i] == -1) {
                color[i] = 1 - color[current];
                q.push(i);
            } else if (adjacencyMatrix[current][i] && color[i] == color[current]) {
                return false;
            }
        }
    }

    return true;
}

int Algorithms::isBipartite(Graph& g) {
    const auto& adjacencyMatrix = g.getAdjacencyMatrix();
    std::vector<int> color(adjacencyMatrix.size(), -1);

    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) { // Use size_t for index type
        if (color[i] == -1) {
            if (!isBipartiteUtil(g, i, color)) {
                return 0;
            }
        }
    }

    return 1;
}

void Algorithms::negativeCycle(Graph& g) {
    const auto& adjacencyMatrix = g.getAdjacencyMatrix();
    std::vector<int> distance(adjacencyMatrix.size(), 0);

    // Perform Bellman-Ford algorithm to detect negative cycles
    size_t size = adjacencyMatrix.size(); // Use size_t for index type
    for (size_t i = 0; i < size; ++i) {
        for (size_t u = 0; u < size; ++u) {
            for (size_t v = 0; v < size; ++v) {
                if (adjacencyMatrix[u][v] != 0) {
                    if (distance[u] + adjacencyMatrix[u][v] < distance[v]) {
                        std::cout << "Negative cycle detected!" << std::endl;
                        return;
                    }
                }
            }
        }
    }

    std::cout << "No negative cycle detected." << std::endl;
}

} // namespace ariel
