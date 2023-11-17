#include <iostream>
using namespace std;

// Recursive approach to calculate Fibonacci number and count steps (recursive calls)
int fibonacciRecursive(int n, int &steps) {
    steps++; // Increment steps counter

    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1, steps) + fibonacciRecursive(n - 2, steps);
}

// Iterative approach to calculate Fibonacci number and count steps (iterations)
int fibonacciIterative(int n, int &steps) {
    if (n <= 1)
        return n;

    int fib = 1, prev = 0, temp;
    for (int i = 2; i <= n; i++) {
        steps++; // Increment steps counter
        temp = fib;
        fib += prev;
        prev = temp;
    }
    return fib;
}

int main() {
    int n, stepsRecursive = 0, stepsIterative = 0;

    cout << "Enter the value of n to calculate Fibonacci: ";
    cin >> n;

    // Calculate Fibonacci number using recursive approach
    int resultRecursive = fibonacciRecursive(n, stepsRecursive);

    // Calculate Fibonacci number using iterative approach
    int resultIterative = fibonacciIterative(n, stepsIterative);

    cout << "Fibonacci number at position " << n << " using recursive approach: " << resultRecursive << endl;
    cout << "Total steps (recursive calls) required for recursive method: " << stepsRecursive << endl;

    cout << "\nFibonacci number at position " << n << " using iterative approach: " << resultIterative << endl;
    cout << "Total steps (iterations) required for iterative method: " << stepsIterative << endl;

    return 0;
}

/*
Recursive fibbonacci:
Time Complexity: O(n*2n)
Auxiliary Space: O(n), For recursion call stack.

Iterative fibbonacci:
Time Complexity: O(n) 
Auxiliary Space: O(1)
*/