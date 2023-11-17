#include <iostream>
using namespace std;

#define N 8

bool isSafe(int board[N][N], int row, int col) {
    // Check for attacks in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper diagonal on the right side
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(int board[N][N], int row) {
    if (row >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1;

            if (solveNQueens(board, row + 1))
                return true;

            board[row][i] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    int board[N][N] = {0}; // Initialize board with 0s

    // Place the first queen at a specified position (for example, row 0, column 3)
    board[0][3] = 1;

    if (solveNQueens(board, 1)) {
        cout << "Solution found:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}

// The time complexity of the backtracking algorithm for 
// the N-Queens problem is exponential, often denoted as O(N!).