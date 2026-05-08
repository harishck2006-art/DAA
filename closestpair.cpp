#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    int x[n], y[n];

    cout << "Enter the points (x y):\n";
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    float minDist = 1e9;
    int p1 = 0, p2 = 1;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float dist = sqrt((x[j] - x[i]) * (x[j] - x[i]) +
                              (y[j] - y[i]) * (y[j] - y[i]));

            if (dist < minDist)
            {
                minDist = dist;
                p1 = i;
                p2 = j;
            }
        }
    }

    cout << "\nClosest Points are:\n";
    cout << "(" << x[p1] << ", " << y[p1] << ") and ";
    cout << "(" << x[p2] << ", " << y[p2] << ")\n";

    cout << "Minimum Distance = " << minDist << endl;

    return 0;
}
[24bcs170@mepcolinux ex2]$g++ close.cpp
[24bcs170@mepcolinux ex2]$./a.out
Enter number of points: 5
Enter the points (x y):
1 2
3 2
6 5
9 8
6 4

Closest Points are:
(6, 5) and (6, 4)
Minimum Distance = 1
[24bcs170@mepcolinux ex2]$./a.out
Enter number of points: 0 1
Enter the points (x y):

Closest Points are:
(1442043056, 0) and (32767, 0)
