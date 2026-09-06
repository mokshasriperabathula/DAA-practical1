#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, amount;

    // Input number of coin types
    cout << "Enter the number of coin types: ";
    cin >> n;

    // Dynamically create array for coins
    int* coins = new int[n];

    // Input coin values
    cout << "Enter the coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Input amount
    cout << "Enter the amount: ";
    cin >> amount;

    // Create DP array
    int* dp = new int[amount + 1];

    // Initialize DP array
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    // Dynamic Programming
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {

            // Check if the coin can be used
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {

                int count = dp[i - coins[j]] + 1;

                // Find minimum number of coins
                if (count < dp[i]) {
                    dp[i] = count;
                }
            }
        }
    }

    // Display result
    if (dp[amount] == INT_MAX) {
        cout << "Change cannot be made.";
    } else {
        cout << "Minimum number of coins required = "
             << dp[amount];
    }

    // Free memory
    delete[] coins;
    delete[] dp;

    return 0;
}
