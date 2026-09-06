#include <iostream>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    int weight[n], value[n];

    cout << "Enter the weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter the values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    // Dynamic Programming table
    int dp[n + 1][capacity + 1];

    // Fill the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            // Base condition
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }

            // If the current item can be included
            else if (weight[i - 1] <= w) {

                int include = value[i - 1] +
                              dp[i - 1][w - weight[i - 1]];

                int exclude = dp[i - 1][w];

                // Find maximum without using max()
                if (include > exclude) {
                    dp[i][w] = include;
                } 
                else {
                    dp[i][w] = exclude;
                }
            }

            // If the item cannot be included
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nMaximum value in Knapsack = " << dp[n][capacity];

    return 0;
}
