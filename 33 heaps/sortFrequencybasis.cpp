#include <bits/stdc++.h>
using namespace std;



void frequencySort(int arr[],int n){
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>> maxH;

    for(int i=0;i<n;i++){   //making map
        mp[arr[i]]++;
    }

    for(auto i = mp.begin();i!=mp.end() ;i++){
        maxH.push({i->second , i->first});
    }

    while(maxH.size()>0){
        int freq = maxH.top().first;
        int ele = maxH.top().second;

        for(int i=0;i<freq;i++){
            cout<<ele<<" ";
        }
        maxH.pop();
    }
}
int main()
{
    int n;
    // cout<<"Enter no. of elements and k resp"<<endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    frequencySort(arr,n);
    return 0;
}