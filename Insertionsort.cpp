#include <iostream>
using namespace std;

// Function to insert last element into sorted part
void insert(int arr[], int n)
{
    // base case
    if (n <= 1)
        return;

    // sort first n-1 elements
    insert(arr, n - 1);

    // take last element
    int last = arr[n - 1];
    int j = n - 2;

    // move elements greater than last
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    // place last element at correct position
    arr[j + 1] = last;
}

// main insertion sort function
void insertionSort(int arr[], int n)
{
    insert(arr, n);
}

// function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// main function
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

[24bcs170@mepcolinux ex4]$g++ insert.cpp
[24bcs170@mepcolinux ex4]$./a.out
Enter the number of elements: 5
Enter 5 elements: -9
6
3
2
5
Sorted array: -9 2 3 5 6
[24bcs170@mepcolinux ex4]$./a.out
Enter the number of elements: 99
Enter 99 elements: 33
22
00
1
5
6
9
^C
[24bcs170@mepcolinux ex4]$./a.out
Enter the number of elements: 6
Enter 6 elements: -9
6
33
22
66
-99
Sorted array: -99 -9 6 22 33 66
[24bcs170@mepcolinux ex4]$./a.out
Enter the number of elements: 8
Enter 8 elements: 55
-2
-0
33
6
9
5

5
Sorted array: -2 0 5 5 6 9 33 55
[24bcs170@mepcolinux ex4]$exit
