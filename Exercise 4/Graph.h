#ifndef EX4_GRAPH_H
#define EX4_GRAPH_H

#include <iostream>
#include <vector>

template<class T>
class Graph {
private:
    std::vector<T> vertices;
    std::vector<std::vector<int> *> weights;

    int findIndex(const T &vertex) {
        for (long unsigned int i = 0; i < vertices.size(); ++i) {
            if (vertices[i] == vertex) {
                return static_cast<int>(i);  // Return the index if found
            }
        }
        return -1;  // Return -1 if not found
    }


public:
    Graph() = default;

    Graph<T> &operator=(const Graph<T> &other) {
        if (this == &other)
            return *this;

        for (int i = 0; i < vertices.size(); ++i) {
            delete weights[i];
        }
        vertices.clear();
        weights.clear();

        vertices = other.vertices;
        for (const auto &row : other.weights) {
            auto *newRow = new std::vector<int>(*row);
            weights.push_back(newRow);
        }

        return *this;
    }

    Graph(const Graph<T> &other) {
        vertices = other.vertices;
        for (const auto &row: other.weights) {
            auto *newRow = new std::vector<int>(*row);
            weights.push_back(newRow);
        }
    }

    ~Graph() {
        for (long unsigned int i = 0; i < vertices.size(); ++i) {
            delete weights[i];
        }
    }

    void addVertex(const T &vertex) {
        if (isVertex(vertex))
            return;
        vertices.push_back(vertex);
        auto *v = new std::vector<int>;
        for (T temp: vertices) {
            v->push_back(-1);
        }
        weights.push_back(v);
        for (std::vector<int> *temp: weights) {
            temp->push_back(-1);
        }
    }

    bool isVertex(const T &vertex) {
        for (const auto &v: vertices) {
            if (v == vertex)
                return true;
        }
        return false;
    }

    void addEdge(const T &from, const T &to, int weight) {
        addVertex(from);
        addVertex(to);
        int i = findIndex(from);
        int j = findIndex(to);
        (*weights[i])[j] = weight;
    }

    void removeVertex(const T &vertex) {
        int index = findIndex(vertex);
        if (index == -1) {
            std::cerr << "Vertex does not exist!" << std::endl;
            return;
        }

        // Remove edges associated with the vertex
        for (int i = 0; i < vertices.size(); ++i) {
            removeEdge(vertices[i], vertex);  // Remove edges going from other vertices to the vertex being removed
            removeEdge(vertex, vertices[i]);  // Remove edges going from the vertex being removed to other vertices
        }

        // Delete the vertex
        vertices.erase(vertices.begin() + index );
        delete weights[index];
        weights.erase(weights.begin() + index );
        // Remove the corresponding row and column in the weights matrix
        for (auto & weight : weights) {
            (*weight)[index] = -1;
            (*weight).erase((*weight).begin() + index);
        }
    }

    void removeEdge(const T &from, const T &to) {
        int indexfrom = findIndex(from);
        int indexto = findIndex(to);
        if (indexfrom == -1 || indexto == -1) {
            std::cerr << "One or both vertices do not exist!" << std::endl;
            return;
        }
        (*weights[indexfrom])[indexto] = -1;
    }

    bool updateEdge(const T &from, const T &to, int weight) {
        int indexfrom = findIndex(from);
        int indexto = findIndex(to);
        if (indexfrom == -1 || indexto == -1) {
            return false;
        }
        (*weights[indexfrom])[indexto] = weight;
        return true;
    }

    int getEdgeWeight(const T &from, const T &to) {
        int indexfrom = findIndex(from);
        int indexto = findIndex(to);
        if (indexfrom == -1 || indexto == -1) {
            return -1;
        }
        return (*weights[indexfrom])[indexto];
    }

    std::vector<T> getNeighbors(const T &vertex) {
        std::vector<T> neighbors;
        int index = findIndex(vertex);
        if (index == -1) {
            return neighbors;
        }
        for (int i = 0; i < vertices.size(); ++i) {
            if ((*weights[index])[i] != -1)
                neighbors.push_back(vertices[i]);
        }
        return neighbors;
    }

    std::vector<T> getConnectedNodes(const T &vertex) {
        std::vector<T> connectedNodes;
        std::vector<bool> visited(vertices.size(), false);
        std::vector<int> currentNodes;
        std::vector<int> nextNodes;
        int index = findIndex(vertex);
        if (index == -1) {
            return connectedNodes;
        }
        visited[index] = true;
        currentNodes.push_back(index);
        for (long unsigned int step = 0; step <= vertices.size(); ++step) {
            for (int i : currentNodes) {
                connectedNodes.push_back(vertices[i]);
                for (long unsigned int j = 0; j < vertices.size(); ++j) {
                    if ((*weights[i])[j] != -1 && !visited[j]) {
                        visited[j] = true;
                        nextNodes.push_back(static_cast<int>(j));
                    }}}
            currentNodes.clear();
            currentNodes = std::move(nextNodes);
            nextNodes.clear();
        }
        // Remove the original vertex from the connectedNodes vector
        std::vector<T> uniqueConnectedNodes;
        for (const auto& node : connectedNodes) {
            if (node != vertex) {
                uniqueConnectedNodes.push_back(node);
            }
        }
        connectedNodes = std::move(uniqueConnectedNodes);
        return connectedNodes;
    }

    std::vector<T> getAdjacentSources(const T &vertex) {
        std::vector<T> adjacentSources;

        // Find the index of the vertex
        int index = findIndex(vertex);
        if (index == -1) {
            std::cerr << "Vertex not found!" << std::endl;
            return adjacentSources;
        }

        // Iterate over all vertices
        for (int i = 0; i < vertices.size(); ++i) {
            // Check if there is an edge from vertex i to the given vertex
            if ((*weights[i])[index] != -1) {
                adjacentSources.push_back(vertices[i]);
            }
        }

        return adjacentSources;
    }

    void printGraph(std::ostream &newout) {
        for (long unsigned int i = 0; i < vertices.size(); ++i) {
            newout << vertices[i] << " ";
            for (long unsigned int j = 0; j < vertices.size(); ++j) {
                if ((*weights[i])[j] != -1)  // Print only if weight is not -1
                    newout << vertices[j] << " ";
            }
            newout << std::endl;
        }
    }
};

#endif //EX4_GRAPH_H
