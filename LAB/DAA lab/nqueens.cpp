#include <stdio.h>
#include <stdbool.h>

int board[20], n;

void printSolution() {
    int i, j;
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (board[i] == j) printf(" Q ");
            else printf(" . ");
        }
        printf("\n");
    }
}

bool isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solve(int row) {
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (row == n) printSolution();
            else solve(row + 1);
        }
    }
}

int main() {
    printf("Enter number of Queens: ");
    scanf("%d", &n);
    solve(1);
    return 0;
}