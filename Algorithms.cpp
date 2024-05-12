#include "Algorithms.hpp"
#include <queue>
#include <iostream>
#include <limits>
#include <stdexcept>

namespace ariel
{

    int Algorithms::minDistance(std::vector<int> distances, std::vector<bool> visited)
    {
        int min = INT32_MAX;
        int min_index = -1;

        for (size_t i = 0; i < distances.size(); i++)
        {
            if (!visited[i] && distances[i] <= min)
            {
                min = distances[i];
                min_index = i;
            }
        }

        return min_index;
    }

    int Algorithms::isConnected(Graph &g)
    {
        const auto &adjacencyMatrix = g.getAdjacencyMatrix();
        std::vector<bool> visited(adjacencyMatrix.size(), false);
        std::queue<size_t> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            size_t current = q.front();
            q.pop();
            for (size_t i = 0; i < adjacencyMatrix[current].size(); ++i)
            {
                if (adjacencyMatrix[current][i] && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        for (bool v : visited)
        {
            if (!v)
                return 0;
        }

        return 1;
    }

    std::string Algorithms::shortestPath(Graph g, int s, int e)
    {
        size_t start = static_cast<size_t>(s);
        size_t end = static_cast<size_t>(e);
        size_t numVertices = g.getNumVertices();

        // Initialize distances array and set the distance from start vertex to itself as 0
        std::vector<int> distances(numVertices, INT32_MAX);
        distances[start] = 0;

        // Initialize vector to store the shortest path
        std::vector<size_t> path(numVertices, SIZE_MAX);

        // Relax edges repeatedly
        for (size_t i = 0; i < numVertices - 1; i++)
        {
            for (size_t u = 0; u < numVertices; u++)
            {
                for (size_t v = 0; v < numVertices; v++)
                {
                    if (g.getValue(u, v) != 0 && distances[u] != INT32_MAX && distances[u] + g.getValue(u, v) < distances[v])
                    {
                        distances[v] = distances[u] + g.getValue(u, v);
                        path[v] = u; // Update the parent vertex for constructing the path
                    }
                }
            }
        }

        // Check for negative cycles
        for (size_t u = 0; u < numVertices; u++)
        {
            for (size_t v = 0; v < numVertices; v++)
            {
                if (g.getValue(u, v) != 0 && distances[u] != INT32_MAX && distances[u] + g.getValue(u, v) < distances[v])
                {
                    return "Negative cycle detected";
                }
            }
        }

        // If end vertex is not reachable from start vertex
        if (distances[end] == INT32_MAX)
        {
            return "-1";
        }

        // Reconstruct the shortest path
        std::string shortestPath = std::to_string(end);
        size_t current = end;
        while (path[current] != SIZE_MAX)
        {
            current = path[current];
            shortestPath = std::to_string(current) + "->" + shortestPath;
        }

        return shortestPath;
    }

    bool isCyclicDFS(Graph &g, size_t v, std::vector<bool> &visited, int parent)
    {
        visited[v] = true;

        const auto &adjacencyMatrix = g.getAdjacencyMatrix();
        for (size_t i = 0; i < adjacencyMatrix[v].size(); ++i)
        {
            if (adjacencyMatrix[v][i])
            {
                if (!visited[i])
                {
                    if (isCyclicDFS(g, i, visited, v))
                    {
                        return true;
                    }
                }
                else if (i != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int Algorithms::isContainsCycle(Graph &g)
    {
        const auto &adjacencyMatrix = g.getAdjacencyMatrix();
        std::vector<bool> visited(adjacencyMatrix.size(), false);

        // Perform DFS traversal from each vertex
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            if (!visited[i] && isCyclicDFS(g, i, visited, -1))
            {
                return 1; // Cycle detected
            }
        }

        return 0; // No cycle found
    }

    std::string Algorithms::isBipartite(Graph g)
    {
        if (hasLoopbacks(g))
        {
            return "The graph is not bipartite";
        }
        std::vector<int> color(g.getNumVertices(), -1);
        color[0] = 1;

        std::queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            size_t curr = static_cast<size_t>(q.front());
            q.pop();

            for (size_t i = 0; i < g.getNumVertices(); i++)
            {
                if (g.getValue(curr, i) != 0)
                {
                    if (color[i] == -1)
                    {
                        color[i] = 1 - color[curr];
                        q.push(i);
                    }
                    else if (g.getValue(curr, i) && color[i] == color[curr])
                    {
                        return "0";
                    }
                }
            }
        }

        std::string ans = "The graph is bipartite: A={";
        bool first = true;
        for (size_t i = 0; i < g.getNumVertices(); i++)
        {
            if (color[i] == 1)
            {
                if (first)
                {
                    ans += std::to_string(i);
                    first = false;
                }
                else
                {
                    ans += ", " + std::to_string(i);
                }
            }
        }
        ans += "}, B={";
        first = true;
        for (size_t i = 0; i < g.getNumVertices(); i++)
        {
            if (color[i] == 0)
            {
                if (first)
                {
                    ans += std::to_string(i);
                    first = false;
                }
                else
                {
                    ans += ", " + std::to_string(i);
                }
            }
        }
        ans += "}";

        return ans;
    }

    bool Algorithms::hasLoopbacks(Graph g)
    {
        for (size_t i = 0; i < g.getNumVertices(); i++)
        {
            if (g.getValue(i, i) != 0)
            {
                return true;
            }
        }

        return false;
    }

    void Algorithms::negativeCycle(Graph &g)
    {
        const auto &adjacencyMatrix = g.getAdjacencyMatrix();
        std::vector<int> distance(adjacencyMatrix.size(), 0);

        // Perform Bellman-Ford algorithm to detect negative cycles
        size_t size = adjacencyMatrix.size();
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t u = 0; u < size; ++u)
            {
                for (size_t v = 0; v < size; ++v)
                {
                    if (adjacencyMatrix[u][v] != 0)
                    {
                        if (distance[u] + adjacencyMatrix[u][v] < distance[v])
                        {
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
