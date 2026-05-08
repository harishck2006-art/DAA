#include <iostream>
#include <string>
using namespace std;

void ShiftTable(string P, int table[256]) {
    int m = P.length();
    for (int i = 0; i < 256; i++) {
        table[i] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        table[(unsigned char)P[j]] = m - 1 - j;
    }
}

int HorspoolMatching(string P, string T) {
    int m = P.length();
    int n = T.length();

    if (m == 0 || m > n) return -1;

    int table[256];
    ShiftTable(P, table);

    int i = m - 1;
    while (i <= n - 1) {
        int k = 0;
        while (k < m && P[m - 1 - k] == T[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1;
        } else {
            i = i + table[(unsigned char)T[i]];
        }
    }
    return -1;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    int result = HorspoolMatching(pattern, text);

    if (result != -1) {
        cout << "Match found at index: " << result << endl;
    } else {
        cout << "No match found." << endl;
    }
    return 0;
}
[24bcs170@mepcolinux ex5]$g++ horspool.cpp
[24bcs170@mepcolinux ex5]$./a.out
Enter the text: hello harish
Enter the pattern: he
Match found at index: 0
[24bcs170@mepcolinux ex5]$./a.out
Enter the text: hello cuteboy
Enter the pattern: boy
Match found at index: 10
[24bcs170@mepcolinux ex5]$./a.out
Enter the text: hi
Enter the pattern: wh
No match found.
[24bcs170@mepcolinux ex5]$exit
