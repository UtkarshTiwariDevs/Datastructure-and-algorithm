#include <bits/stdc++.h>
using namespace std;
int floorSortedArray(int n, int a[], int ele)
{
    int s = 0, e = n - 1;
    int res =-1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (a[mid] == ele)
        {
            return a[mid];
        }
        else if (a[mid] > ele)
            e = mid - 1;
        else if (a[mid] < ele)
        {
            s = mid + 1;
            res = a[mid];
        }
    }
    return res;
}
int main()
{
    int a[] = {1, 2, 3, 4, 8, 10, 10, 16};
    int n = 8;
    int ele = 5;
    cout << floorSortedArray(n, a, ele);

    return 0;
}
