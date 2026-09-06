#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of matrices: ";
    cin >> n;

    // Check for valid input
    if (n <= 0) {
        cout << "Invalid number of matrices!";
        return 0;
    }

    // Dynamically allocate the dimension array
    int* p = new int[n + 1];

    cout << "Enter " << n + 1 << " dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    // Dynamically allocate DP table
    int** dp = new int*[n];

    for (int i = 0; i < n; i++) {
        dp[i] = new int[n];
    }

    // Initialize diagonal elements
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Length of the matrix chain
    for (int length = 2; length <= n; length++) {

        for (int i = 0; i < n - length + 1; i++) {

            int j = i + length - 1;

            // Initialize with a large value
            dp[i][j] = INT_MAX;

            // Try all possible divisions
            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i] * p[k + 1] * p[j + 1];

                // Find minimum cost
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << "\nMinimum number of multiplications = "
         << dp[0][n - 1] << endl;

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] dp[i];
    }

    delete[] dp;
    delete[] p;

    return 0;
}
