#include <bits/stdc++.h>
using namespace std;

int bs(int n, int ele, int a[])
{
    int start = 0, end = n - 1;
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == ele)
        {
            res = mid;
            end = mid-1;
        }
        else if (a[mid] > ele)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return res;
}
int main()
{
    int a[] = {2 ,4,10,10,10,18,20};
    int n = 7  ;
    int ele;
    cin >> ele;
    int index = bs(n, ele, a);
    cout << index;
    return 0;
}
