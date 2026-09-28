#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> selected(V, 0);
    selected[0] = 1;

    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int edge = 0; edge < V - 1; edge++) {
        int minWeight = 999999;
        int x = -1, y = -1;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j] != 0 &&
                        graph[i][j] < minWeight) {
                        minWeight = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y
             << " : " << minWeight << endl;

        totalCost += minWeight;
        selected[y] = 1;
    }

    cout << "Total Minimum Cost = " << totalCost << endl;

    return 0;
}
