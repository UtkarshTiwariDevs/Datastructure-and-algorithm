#include <bits/stdc++.h>
using namespace std;

vector<int> kSorted(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> minH;
    vector<int> ve;
    for(int i=0;i<n;i++){
        minH.push(arr[i]);
        if(minH.size()>k){
            ve.push_back(minH.top());
            minH.pop();
        }
    }
    while(minH.size()>0){
        ve.push_back(minH.top());
        minH.pop();
    }
    return ve;
}

int main()
{
    int n, k;
    // cout<<"Enter no. of elements and k resp"<<endl;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ve = kSorted(arr,n,k);
    for(int i =0 ;i<ve.size();i++){
        cout<<ve[i]<<" ";
    }
    
    return 0;
}