#include <iostream>
using namespace std;

class NQueens {
private:
    int N;
    int **board;

public:
    NQueens(int n) : N(n) {
        // Dynamically allocate an N x N chessboard
        board = new int*[N];
        for (int i = 0; i < N; i++) {
            board[i] = new int[N]();
        }
    }

    // Function to print the board
    void printBoard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1)
                    cout << "Q ";  // Print 'Q' for a queen
                else
                    cout << ". ";  // Print '.' for empty space
            }
            cout << endl;
        }
        cout << endl;
    }

    // Check if a queen can be placed at board[row][col]
    bool isSafe(int row, int col) {
        // Check the column for any queen
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1) {
                return false;
            }
        }

        // Check the upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        // Check the upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    // Backtracking function to solve the N-Queens problem
    bool solveNQueens(int row) {
        // If all queens are placed
        if (row >= N) {
            return true;
        }

        // Try all columns for the current row
        for (int col = 0; col < N; col++) {
            if (isSafe(row, col)) {
                // Place the queen
                board[row][col] = 1;

                // Recur to place the next queen
                if (solveNQueens(row + 1)) {
                    return true;
                }

                // If placing queen at (row, col) doesn't lead to a solution,
                // backtrack
                board[row][col] = 0;
            }
        }

        // If no place is found for this row, return false
        return false;
    }

    // Function to solve and print the board
    void solve() {
        if (solveNQueens(0)) {
            printBoard();
        } else {
            cout << "No solution exists." << endl;
        }
    }

    ~NQueens() {
        // Deallocate the dynamically allocated memory for the board
        for (int i = 0; i < N; i++) {
            delete[] board[i];
        }
        delete[] board;
    }
};

int main() {
    int N;
    cout << "Enter the size of the board (N): ";
    cin >> N;

    NQueens nq(N);
    nq.solve();

    return 0;
}
