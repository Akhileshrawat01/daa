#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

using namespace std;
using namespace std::chrono;

const int SIZE = 100; // Adjust matrix size here

void singleThreadedMatrixMultiplication(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiThreadedMatrixMultiplicationRow(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C) {
    #pragma omp parallel for
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiThreadedMatrixMultiplicationCell(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    vector<vector<int>> A(SIZE, vector<int>(SIZE, 1));
    vector<vector<int>> B(SIZE, vector<int>(SIZE, 1));
    vector<vector<int>> C(SIZE, vector<int>(SIZE, 0));

    high_resolution_clock::time_point start, end;
    duration<double> time_span;

    // Single-threaded matrix multiplication
    start = high_resolution_clock::now();
    singleThreadedMatrixMultiplication(A, B, C);
    end = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(end - start);
    cout << "Single-threaded matrix multiplication time: " << time_span.count() << " seconds.\n";

    // Multithreaded matrix multiplication (One thread per row)
    start = high_resolution_clock::now();
    multiThreadedMatrixMultiplicationRow(A, B, C);
    end = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(end - start);
    cout << "Multithreaded (One thread per row) matrix multiplication time: " << time_span.count() << " seconds.\n";

    // Multithreaded matrix multiplication (One thread per cell)
    start = high_resolution_clock::now();
    multiThreadedMatrixMultiplicationCell(A, B, C);
    end = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(end - start);
    cout << "Multithreaded (One thread per cell) matrix multiplication time: " << time_span.count() << " seconds.\n";

    return 0;
}
