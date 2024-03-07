#include <iostream>
#include <vector>
using namespace std;

// Size of the chessboard
const int N = 4;

// Possible moves for the knight
const int moveX[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int moveY[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Function to print the chessboard
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to check if a move is valid
bool isSafe(int x, int y, int board[N][N]) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}

// Recursive function to find the knight's tour
bool solveKnightTour(int x, int y, int move, int board[N][N]) {
    if (move == N * N) {
        return true; // All squares have been visited
    }

    // Try all possible moves from the current cell
    for (int i = 0; i < 8; i++) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];

        if (isSafe(nextX, nextY, board)) {
            board[nextX][nextY] = move;
            if (solveKnightTour(nextX, nextY, move + 1, board)) {
                return true;
            }
            board[nextX][nextY] = -1; // Backtrack
        }
    }

    return false;
}

// Main function to find and print the Knight's Tour
void knightTour() {
    int board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1; // Initialize the board
        }
    }

    // Starting position
    int startX = 0;
    int startY = 0;

    board[startX][startY] = 0; // Mark the starting cell

    if (solveKnightTour(startX, startY, 1, board)) {
        cout << "Solution exists:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {
    knightTour();
    return 0;
}
