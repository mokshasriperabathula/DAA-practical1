#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store an edge
// Each edge has source vertex, destination vertex and weight
struct Edge {
    int u, v, weight;
};

// Function to compare two edges
// Used to sort edges in increasing order of weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find the parent of a vertex
int findParent(vector<int>& parent, int vertex) {

    // If vertex is its own parent, return it
    if (parent[vertex] == vertex)
        return vertex;

    // Find the parent recursively
    // Path compression is used here
    return parent[vertex] =
        findParent(parent, parent[vertex]);
}

// Function to join two sets
void unionSet(vector<int>& parent, vector<int>& rank,
              int u, int v) {

    // Find the parent of both vertices
    u = findParent(parent, u);
    v = findParent(parent, v);

    // If parents are different, they belong to different sets
    if (u != v) {

        // Join the smaller rank tree with larger rank tree
        if (rank[u] < rank[v])
            parent[u] = v;

        else if (rank[u] > rank[v])
            parent[v] = u;

        else {
            // If both ranks are same
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main() {

    int V, E;

    // Take number of vertices
    cout << "Enter number of vertices: ";
    cin >> V;

    // Take number of edges
    cout << "Enter number of edges: ";
    cin >> E;

    // Create a vector to store all edges
    vector<Edge> edges(E);

    // Take edge information from user
    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < E; i++) {

        // Input source, destination and weight
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Sort all edges in increasing order of weight
    sort(edges.begin(), edges.end(), compare);

    // Parent array for Disjoint Set
    vector<int> parent(V);

    // Rank array used to keep the tree balanced
    vector<int> rank(V, 0);

    // Initially, every vertex is its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Stores total weight of MST
    int totalCost = 0;

    // Counts number of edges selected for MST
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    // Process edges one by one
    // Edges are already sorted by weight
    for (Edge edge : edges) {

        // Find parent of source vertex
        int u = findParent(parent, edge.u);

        // Find parent of destination vertex
        int v = findParent(parent, edge.v);

        // If parents are different, adding this edge
        // will not create a cycle
        if (u != v) {

            // Display selected edge
            cout << edge.u << " - "
                 << edge.v << " : "
                 << edge.weight << endl;

            // Add edge weight to total cost
            totalCost += edge.weight;

            // Join the two sets
            unionSet(parent, rank, u, v);

            // Increase the count of selected edges
            count++;

            // MST contains V-1 edges
            if (count == V - 1)
                break;
        }
    }

    // Display total minimum cost
    cout << "Total Minimum Cost = "
         << totalCost << endl;

    return 0;
}
