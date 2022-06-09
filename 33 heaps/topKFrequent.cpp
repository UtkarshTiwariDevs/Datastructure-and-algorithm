#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> pi;

void kFrequent(int arr[],int n,int k){
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
    // priority_queue<pi,vector<pi>,greater<pi>> minH;

    for(int i=0;i<n;i++){   //making map
        mp[arr[i]]++;
    }

    for(auto i = mp.begin();i!=mp.end() ;i++){
        minH.push({i->second , i->first});
        if(minH.size()>k){
            minH.pop();
        }
    }

    while(minH.size()>0){
        cout<<minH.top().second<<" ";
        minH.pop();
    }
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
    
    kFrequent(arr,n,k);
    return 0;
}