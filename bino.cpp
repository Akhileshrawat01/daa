#include <iostream>
using namespace std;

int binomialCoefficients(int n, int k) {
     if (n < k) {
        cout << "Binomial coefficient C(" << n << ", " << k << ") is not defined as n < k.\n";
        return -1; // Returning a sentinel value (-1) to indicate an undefined result
    }
    int dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = binomialCoefficients(n, k);
    cout << "Binomial coefficient C(" << n << ", " << k << ") is: " << result << endl;

    return 0;
}

// The time complexity of the dynamic programming approach for 
// calculating binomial coefficients using the above code is 
// O(n×k).

// The outer loop runs 'n' times.
// The inner loop runs 'k' times or 'i' times, whichever is smaller.
// Therefore, the overall time complexity is O(n×k), 
// where 'n' and 'k' are the given values for calculating the 
// binomial coefficient C(n,k).