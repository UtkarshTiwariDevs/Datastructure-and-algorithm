#include <bits/stdc++.h>
using namespace std;

int bs(int n, int a[])
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (a[mid] <= a[next] && a[mid] <= a[prev])
        {
            return mid;
        }
        else if (a[mid] <= a[end])
            end = mid - 1;
        else if (a[mid] >= a[start])
            start = mid + 1;
    }
    return 0;
}
int main()
{
    int a[] = {11,12,15,18,2,5,6,8};
    int n = 8;
    int index = bs(n,a);
    cout << index;

    return 0;
}
