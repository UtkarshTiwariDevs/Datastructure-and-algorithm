#include <bits/stdc++.h>
using namespace std;

int sumBtwK1K2(int arr[], int n,int k1,int k2)
{
    priority_queue<int> maxH;
    for(int i = 0 ;i<n;i++){
        maxH.push(arr[i]);
        if(maxH.size()>k1){
            maxH.pop();
        }
    }
    int first = maxH.top();
    while(maxH.size()>0){
        maxH.pop();
    }
    for(int i = 0 ;i<n;i++){
        maxH.push(arr[i]);
        if(maxH.size()>k2){
            maxH.pop();
        }
    }
    int second = maxH.top();
    while(maxH.size()>0){
        maxH.pop();
    }
    int sum = 0;
    for(int i =0;i<n;i++){
        if(arr[i]>first && arr[i]<second){
            sum+=arr[i];
        }
    }
    return sum;
}

int main()
{
    int n,k1,k2;
    // cout<<"Enter no. of elements and k resp"<<endl;
    cin >> n>>k1>>k2;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<sumBtwK1K2(arr,n,k1,k2);
    return 0;
}