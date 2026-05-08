#include <iostream>
using namespace std;

int main()
{
    int n, temp, minIndex;
    int * a;

    cout << "Enter number of elements: ";
    cin >> n;

    a = new int[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
    {
       cin >> a[i];
    }

        cout << "Before Sorting:\n";
    for(int i = 0; i < n; i++)
    {
       cout << a[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < n-1; i++)
    {
        minIndex = i;

        for(int j = i+1; j < n; j++)
        {
            if(a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }


        if(minIndex != i)
        {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
    {
       cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}
[24bcs170@mepcolinux ex1]$g++ selection_sort.cpp
[24bcs170@mepcolinux ex1]$./a.out
Enter number of elements: 6
Enter elements:
3
2
9
8
7
12
Before Sorting:
3 2 9 8 7 12
Sorted array:
2 3 7 8 9 12
[24bcs170@mepcolinux ex1]$./a.out
Enter number of elements: 9
Enter elements:
4
6
33
22
11
00
55
88
90
Before Sorting:
4 6 33 22 11 0 55 88 90
Sorted array:
0 4 6 11 22 33 55 88 90
