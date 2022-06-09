#include <bits/stdc++.h>
using namespace std;

int isValid(int n,int k,int m,int a[])
{
    int s = 0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum += a[i];
        if(sum > m)
        {
            s++;
            sum = a[i];
        }
    }
    return s+1;
}
int pages(int n,int a[],int k)
{   
    if(k>n)
        return -1;

    int sum = 1;
    int maxPages = INT_MIN;
    for(int i = 0;i<n;i++)
    {
        sum+=a[i];
        maxPages = max(maxPages,a[i]);
    }

    int s= maxPages;
    int e = sum;
    int res =-1;
    while(s<=e)
    {
        int m = s + (e-s)/2;
        int count = isValid(n,k,m,a);
        if(count <= k)
        {
            res = m;
            e = m-1;
        }
        else   
            s=m+1;
    }
    return res;
}
int main()
{
    int a[] = {10,20,30,40};
    int n =4 ;
    int k = 2;
    cout<<pages;
    return 0;
}
