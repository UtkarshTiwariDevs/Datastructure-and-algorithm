// find first occ of 1 in binary infinite array

#include <bits/stdc++.h>
using namespace std;

int infSortedArr(int a[])
{
    int s = 0;
    int e = 1;
    int res = -1;
    while (a[e] < 1)
    {
        s = e;
        e = 2 * e;
    }

    while (s <= e)
    {
        int m = (s + e) / 2;
        if (a[m] == 1)
        {
            res = m;
            e = m - 1;
        }
        else if (a[m] < 1)
            s = m + 1;
        else
            e = m-1;
    }
    return res;
}
int main()
{
    int a[] = {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1}; // infi arr

    cout << infSortedArr(a);
    return 0;
}
