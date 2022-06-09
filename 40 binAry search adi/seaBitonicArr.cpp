#include <bits/stdc++.h>
using namespace std;

int bsasc(int a[],int s ,int e,int key)
{
    while(s<=e)
    {
        int m = (s+e)/2;
        if(a[m]==key)
            return m;
        else if(a[m] > key)
            e = m-1;
        else
            s =m+1;
    }
    return -1;
}
int bsdesc(int a[],int s ,int e,int key)
{
    while(s<=e)
    {
        int m = (s+e)/2;
        if(a[m]==key)
            return m;
        else if(a[m] > key)
            s =m+1;
        else
            e = m-1;
    }
    return -1;
}
int peak(int n,int a[],int key)
{
    int s=0,e=n-1;
    int peakp = -1;
    while(s<=e)
    {
        int m = s+(e-s)/2;
        if((m-1<0 || a[m] >= a[m-1]) && (m+1>=n || a[m]>=a[m+1]))
        {
            peakp  = m;
            break;
        }
        else if(a[m+1] > a[m])
            s = m+1;
        else
            e = m-1;
    }
    // return peakp;
    int left = bsasc(a,0,peakp,key);
    int right = bsdesc(a,peakp+1,n-1,key);
    if(left ==-1 && right==-1)
        return -1;
    else
    {
        if(left ==-1)
            return right;
        else 
            return left;
    }
}
int main()
{
    int a[] = {1,3,8,12,5,4 ,2};
    int n =7 ;
    int ele = 4;
    cout<<peak(n,a,ele);
    return 0;
}

// bs desc and agnostic done in copy