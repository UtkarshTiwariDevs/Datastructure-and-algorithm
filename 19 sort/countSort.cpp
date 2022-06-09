#include <iostream>
using namespace std;

void countSort(int arr[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    int count[100] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    int output[n] = {0};
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
int main()
{
    int arr[] = {1,1,3,4,4,5,9,9,8,8,7,7,7,7,7,6,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}