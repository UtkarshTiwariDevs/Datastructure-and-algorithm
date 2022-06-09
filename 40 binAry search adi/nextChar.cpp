#include <bits/stdc++.h>
using namespace std;
char nextGreat(int n,char a[],char target)
{
    int s=0,e=n-1;
    char ans;

    while(s<=e)
    {
        int mid = s + (e-s)/2;
        int val = a[mid] - 'a';
        if(val > (target - 'a'))
        {
            ans = a[mid];
            e  =mid-1;
        }
        else s = mid+1;

    }
    return ans;
}
int main()
{
    char a[] = {'a','c','f','h'};
    int n = 4;
    char target = 'f';
    cout<<nextGreat(n,a,target);

    return 0;
}