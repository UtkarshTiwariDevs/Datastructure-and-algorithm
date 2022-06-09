#include <bits/stdc++.h>
using namespace std;

int bsNearlySorted(int n, int a[], int ele)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (a[mid] == ele)
            return mid;
        else if ((mid - 1) >= s && a[mid - 1] == ele)
            return mid - 1;
        else if ((mid + 1) <= e && a[mid + 1] == ele)
            return mid + 1;
        else if (a[mid] > ele)
            e = mid - 2;
        else if (a[mid] < ele)
            s = mid + 2;
    }
    return -1;
}
int main()
{
    int a[] = {5, 10, 30, 20, 40};
    int n = 5;
    int ele = 20;
    cout << bsNearlySorted(n,a,ele);

    return 0;
}
