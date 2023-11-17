#include <iostream>
using namespace std;

int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n], values[n];
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> weights[i] >> values[i];
    }

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int maxValue = knapsack(capacity, weights, values, n);

    cout << "The maximum value that can be obtained: " << maxValue << endl;

    return 0;
}


// The time complexity of the dynamic programming solution for the 0-1 Knapsack problem is O(n * capacity), 
// where n is the number of items and capacity is the capacity of the knapsack.
//  This is because the DP table is of size (n+1) x (capacity+1), 
//  and each cell requires constant time to compute based on the values of the 
//  previous cells in the table. 
// Therefore, the overall time complexity is O(n * capacity).