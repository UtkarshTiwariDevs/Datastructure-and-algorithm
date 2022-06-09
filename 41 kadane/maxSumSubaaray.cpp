#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++)
        cin>>a[i];
    
    int sum =0 ;
    int maxS=a[0];
    for(int i=0;i<n;i++)
    {
        sum += a[i];
        maxS = max(maxS,sum);
        if(sum < 0)
            sum=0;
    }
    cout<<maxS; 
    return 0;
}