#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int capacity, Item arr[], int n) {
    sort(arr, arr + n, compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + arr[i].weight <= capacity) {
            currentWeight += arr[i].weight;
            totalValue += arr[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += arr[i].ratio * remainingWeight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    Item arr[n];
    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
        arr[i].ratio = static_cast<double>(arr[i].value) / arr[i].weight;
    }

    double maxValue = fractionalKnapsack(capacity, arr, n);

    cout << "The maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
