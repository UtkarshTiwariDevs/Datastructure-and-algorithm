#include <bits/stdc++.h>
using namespace std;

int bs(int n, int ele, int a[])
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == ele)
            return a[mid];
        else if (a[mid] > ele)
            end = mid - 1;
        else
            start = mid + 1;
    }
    
    int left=abs(a[start] - ele);
    int right = abs(a[end] - ele);
    if(left<right)
        return a[start];
    else
        return a[end];
}
int main()
{
    int a[] = {1, 3,8,10,15};
    int n =5 ;
    int ele = 12;
    cout<<bs(n,ele,a);
    return 0;
}

// bs desc and agnostic done in copy