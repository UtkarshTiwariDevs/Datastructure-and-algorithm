#include <bits/stdc++.h>

using namespace std;

int kedaneSum(int a[],int n){
    int curSum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        curSum+=a[i];
        if(curSum<0){
            curSum=0;
        }
        maxSum=max(maxSum,curSum);
    }
    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int wrapSum=0;
    int nonWrapSum = kedaneSum(a,n);
    int totalSum=0;
    for(int i =0;i<n;i++){
        totalSum+=a[i];
        a[i]=-a[i];
    }
    wrapSum=totalSum+kedaneSum(a,n);
    cout<<max(wrapSum,nonWrapSum)<<endl;    
}
