[?1034h[24bcs170@mepcolinux ex6]$cat floyd.cpp
#include <iostream>
using namespace std;

// Function to display the matrix
void displayMatrix(int D[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == 9999)
                cout << "INF\t";
            else
                cout << D[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Main Floyd's Algorithm Function
void floydAlgorithm(int W[][100], int D[][100], int n) {
    // Step 1: Initialize D with W
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            D[i][j] = W[i][j];
        }
    }

    // Step 2: Floyd's Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] != 9999 && D[k][j] != 9999) {
                    if (D[i][k] + D[k][j] < D[i][j]) {
                        D[i][j] = D[i][k] + D[k][j];
                    }
                }
            }
        }
    }
}

// Main Function
int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int W[100][100];

    cout << "\nEnter weight matrix values (9999 for INF):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "W[" << i << "][" << j << "]: ";
            cin >> W[i][j];
        }
    }

    int D[100][100];

    cout << "\n=== FLOYD'S ALGORITHM ===\n\n";
    cout << "Original Matrix:\n";
    displayMatrix(W, n);

    floydAlgorithm(W, D, n);

    cout << "\nShortest Path Matrix:\n";
    displayMatrix(D, n);

    return 0;
}
[24bcs170@mepcolinux ex6]$g++ floyd.cpp
[24bcs170@mepcolinux ex6]$./a.out
Enter number of vertices: 4

Enter weight matrix values (9999 for INF):
W[0][0]: 0
W[0][1]: 5
W[0][2]: 9999
W[0][3]: 10
W[1][0]: 9999
W[1][1]: 0
W[1][2]: 3
W[1][3]: 9999
W[2][0]: 9999
W[2][1]: 9999
W[2][2]: 0
W[2][3]: 1
W[3][0]: 9999
W[3][1]: 9999
W[3][2]: 9999
W[3][3]: 0

=== FLOYD'S ALGORITHM ===

Original Matrix:
0       5       INF     10
INF     0       3       INF
INF     INF     0       1
INF     INF     INF     0

Shortest Path Matrix:
0       5       8       9
INF     0       3       4
INF     INF     0       1
INF     INF     INF     0
[24bcs170@mepcolinux ex6]$./a.out
Enter number of vertices: 5

Enter weight matrix values (9999 for INF):
W[0][0]: 0
W[0][1]: 3
W[0][2]: 2
W[0][3]: 1
W[0][4]: 9999
W[1][0]: 9999
W[1][1]: 9999
W[1][2]: 36
W[1][3]: 2
W[1][4]: 5
W[2][0]: 9999
W[2][1]: 02
W[2][2]: 33
W[2][3]: 96
W[2][4]: 87
W[3][0]: 63
W[3][1]: 54
W[3][2]: 9999
W[3][3]: 333
W[3][4]: 01
W[4][0]: 225
W[4][1]: 99999
W[4][2]: 2
W[4][3]: 14
W[4][4]: 36

=== FLOYD'S ALGORITHM ===

Original Matrix:
0       3       2       1       INF
INF     INF     36      2       5
INF     2       33      96      87
63      54      INF     3       1
225     INF     2       14      36

Shortest Path Matrix:
0       3       2       1       2
65      7       5       2       3
67      2       7       4       5
63      5       3       3       1
69      4       2       6       7
[24bcs170@mepcolinux ex6]$exit
exit
