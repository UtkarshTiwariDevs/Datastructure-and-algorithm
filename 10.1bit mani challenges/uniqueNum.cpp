#include <iostream>
using namespace std;

int uniqueNum(int a[], int n)
{
    int arrsum = 0;
    for (int i = 0; i < n; i++)
    {
        arrsum = arrsum ^ a[i];
    }
    return arrsum;
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 5, 4, 3, 2};
    cout << uniqueNum(arr, 9) << endl;
    return 0;
}