#include <bits/stdc++.h>
using namespace std;

void swap(int arrr[], int pos1, int pos2)
{
    int temp = arrr[pos1];
    arrr[pos1] = arrr[pos2];
    arrr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot)
{
    int i = low;
    int j = low;
    while (i <= high)
    {
        if (arr[i] > pivot)
            i++;
        else
        {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int pos = partition(arr, low, high, pivot);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}

int main()
{
    int arr[] = {1, 61, 23};
    quickSort(arr, 0, 3);
    for (auto p : arr)
    {
        cout << p << " ";
    }
}