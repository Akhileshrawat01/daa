#include<bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

void jobSequence(Job arr[], int n) {
    sort(arr, arr + n, compare);

    int result[n];
    bool slot[n] = { false };

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "The sequence of jobs to maximize profit while meeting deadlines:\n";
    for (int i = 0; i < n; i++) {
        if (slot[i])
            cout << "Job " << arr[result[i]].id << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    cout << "Enter the job details (ID, Deadline, Profit):\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }

    jobSequence(arr, n);

    return 0;
}
