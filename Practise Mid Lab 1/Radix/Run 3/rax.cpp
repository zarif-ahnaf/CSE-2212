#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (mx < arr[i])
            mx = arr[i];
    }
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};
    int i;
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    for (auto p : arr)
    {
        cout << p << " ";
    }
    return 0;
}