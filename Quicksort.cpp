#include <iostream>
using namespace std;

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];     // choose first element as pivot
    int i = low + 1;
    int j = high;

    while (true)
    {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (j >= low && arr[j] > pivot)
            j--;

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
            break;
    }

    // place pivot in correct position
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

// QuickSort function
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    quicksort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

[24bcs170@mepcolinux ex3]$g++ quick.cpp
[24bcs170@mepcolinux ex3]$./a.out
Enter number of elements: 6
Enter elements:
-3
-2
1
0
21
33
Sorted array:
-3 -2 0 1 21 33 [24bcs170@mepcolinux ex3]$./a.out
Enter number of elements: 3
Enter elements:
3
2
1
Sorted array:
1 2 3 [24bcs170@mepcolinux ex3]$exit
exit
