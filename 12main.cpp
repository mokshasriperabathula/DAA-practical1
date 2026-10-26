// Part of code                         Complexity
 // ---------------------------------------------------
 // Initializing DP table                O(n * 2^n)
 // Processing DP states                 O(n^2 * 2^n)
 // Reconstructing optimal tour          O(n^2)
 // ---------------------------------------------------
 // Overall                              O(n^2 * 2^n)

 // Time Complexity: O(n^2 * 2^n)
 // Space Complexity: O(n * 2^n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  
#include <chrono>
 
using namespace std;
using namespace chrono;


// Find minimum cost using Dynamic Programming
int tsp(int mask, int pos,
        vector<vector<int>> &cost,  
        vector<vector<int>> &dp,
        int n, long long &operations)
{
    // All cities visited: return to starting city
    if(mask == (1 << n) - 1)
    {
        operations++;
        return cost[pos][0];
    }

    // Return previously calculated result
    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    // Try every unvisited city
    for(int city = 0; city < n; city++)
    {
        operations++;

        if(!(mask & (1 << city)))
        {
            int newMask = mask | (1 << city);

            int remainingCost =
                tsp(newMask, city, cost, dp,
                    n, operations);

            int totalCost = cost[pos][city] + remainingCost;

            ans = min(ans, totalCost);
        }
    }

    return dp[mask][pos] = ans;
}


int main()
{
    int n = 4;

    // Cost adjacency matrix
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "========== TRAVELLING SALESMAN PROBLEM ==========\n";

    cout << "\nNumber of Cities : " << n;

    cout << "\n\nGraph Edges with Costs:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            cout << char('A' + i) << " -- "
                 << char('A' + j) << " : "
                 << cost[i][j] << '\n';
        }
    }

    // Initialize DP table
    vector<vector<int>> dp(1 << n,
                           vector<int>(n, -1));

    long long operations = 0;

    auto start = high_resolution_clock::now();

    // Start from city A (city 0)
    int minCost = tsp(1, 0, cost, dp,
                      n, operations);

    auto end = high_resolution_clock::now();

    auto timeTaken =
        duration_cast<nanoseconds>(end - start);


    // Reconstruct the optimal tour
    cout << "\n========== OPTIMAL TOUR ==========\n";

    int mask = 1;
    int pos = 0;

    cout << "Route: A";

    while(mask != (1 << n) - 1)
    {
        int bestCity = -1;
        int bestCost = INT_MAX;

        for(int city = 0; city < n; city++)
        {
            if(!(mask & (1 << city)))
            {
                int nextMask = mask | (1 << city);

                int total =
                    cost[pos][city] +
                    tsp(nextMask, city, cost, dp,
                        n, operations);

                if(total < bestCost)
                {
                    bestCost = total;
                    bestCity = city;
                }
            }
        }

        pos = bestCity;
        mask |= (1 << pos);

        cout << " -> " << char('A' + pos);
    }

    cout << " -> A";

    cout << "\nMinimum Total Cost : " << minCost;


    // Display performance details
    cout << "\n\n========== PERFORMANCE ==========";

    cout << "\nOperations       : " << operations;

    cout << "\nExecution Time   : "
         << timeTaken.count() << " ns";

    return 0;
}
