#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++)
        cin>>a[i];
    
    int maxS = INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum =0;
            for(int k=i;k<=j;k++)
            {
                sum += a[k];
            }
            maxS = max(maxS,sum);
        }
    }
    for(int i=0;i<n;i++)
    {
        int sum =0;
        for(int j=i;j<n;j++)
        {
            sum += a[j]; 
        }
        maxS = max(maxS,sum);
    }
    cout<<maxS;
    return 0;
}