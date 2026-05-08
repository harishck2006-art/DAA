#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h> // Extra safety for abs()

using namespace std;

// Space kuduthuruken vector kulla '> >'
bool isSafe(vector<vector<int> >& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                // abs functionality
                int r_diff = row - i;
                int c_diff = col - j;
                if (r_diff < 0) r_diff = -r_diff;
                if (c_diff < 0) c_diff = -c_diff;

                if (r_diff == c_diff)
                    return false;
            }
        }
    }
    return true;
}

bool solveNQ(vector<vector<int> >& board, int row, int n) {
    if (row == n) return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveNQ(board, row + 1, n)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    // Space added between > >
    vector<vector<int> > board(n, vector<int>(n, 0));

    if (!solveNQ(board, 0, n)) {
        cout << "No solution exists" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] ? "Q " : ". ");
            }
            cout << endl;
        }
    }
    return 0;
}

[24bcs170@mepcolinux ex7]$g++ q.cpp
[24bcs170@mepcolinux ex7]$./a.out
Enter N: 4
. Q . .
. . . Q
Q . . .
. . Q .
[24bcs170@mepcolinux ex7]$./a.out
Enter N: 8
Q . . . . . . .
. . . . Q . . .
. . . . . . . Q
. . . . . Q . .
. . Q . . . . .
. . . . . . Q .
. Q . . . . . .
. . . Q . . . .
[24bcs170@mepcolinux ex7]$./a.out
Enter N: 16
Q . . . . . . . . . . . . . . .
. . Q . . . . . . . . . . . . .
. . . . Q . . . . . . . . . . .
. Q . . . . . . . . . . . . . .
. . . . . . . . . . . . Q . . .
. . . . . . . . Q . . . . . . .
. . . . . . . . . . . . . Q . .
. . . . . . . . . . . Q . . . .
. . . . . . . . . . . . . . Q .
. . . . . Q . . . . . . . . . .
. . . . . . . . . . . . . . . Q
. . . . . . Q . . . . . . . . .
. . . Q . . . . . . . . . . . .
. . . . . . . . . . Q . . . . .
. . . . . . . Q . . . . . . . .
. . . . . . . . . Q . . . . . .
[24bcs170@mepcolinux ex7]$exit
exit
