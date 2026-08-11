#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

class Graph {
    int vertices;
    vector<vector<int>> graph;

public:
    Graph(int n) {
        vertices = n;
        graph.resize(n);
    }

    void connect(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);   // Remove this line for directed graph
    }

    void performDFS(int current, vector<bool>& marked) {
        marked[current] = true;
        cout << current << " ";

        for (int next : graph[current]) {
            if (!marked[next]) {
                performDFS(next, marked);
            }
        }
    }

    void DFS(int source) {
        vector<bool> marked(vertices, false);
        performDFS(source, marked);
    }

    void BFS(int source) {
        vector<bool> marked(vertices, false);
        queue<int> nodes;

        marked[source] = true;
        nodes.push(source);

        while (!nodes.empty()) {
            int current = nodes.front();
            nodes.pop();

            cout << current << " ";

            for (int next : graph[current]) {
                if (!marked[next]) {
                    marked[next] = true;
                    nodes.push(next);
                }
            }
        }
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph graph(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int from, to;
        cin >> from >> to;
        graph.connect(from, to);
    }
    int source;
    cout << "Enter starting vertex: ";
    cin >> source;

    // DFS Time Analysis
    auto dfsStart = high_resolution_clock::now();
    cout << "\nDFS Traversal: ";
    graph.DFS(source);
    auto dfsEnd = high_resolution_clock::now();
    auto dfsDuration =
        duration_cast<nanoseconds>(dfsEnd - dfsStart);
  
    // BFS Time Analysis
    auto bfsStart = high_resolution_clock::now();
    cout << "\n\nBFS Traversal: ";
    graph.BFS(source);
    auto bfsEnd = high_resolution_clock::now();
    auto bfsDuration =
        duration_cast<nanoseconds>(bfsEnd - bfsStart);

    cout << "\n\nExecution Time:";
    cout << "\nDFS: " << dfsDuration.count() << " ns";
    cout << "\nBFS: " << bfsDuration.count() << " ns";
    return 0;
}
