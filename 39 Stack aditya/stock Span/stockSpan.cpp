#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(int n,int a[])
{
    stack<pair<int,int>> s;
    vector<int> v;

    for(int i=0;i<n;i++)
    {
        if(s.size() == 0)   
            v.push_back(-1);
        else if(s.size()>0 && a[i] < s.top().first)
            v.push_back(s.top().second);
        else if((s.size()>0 && a[i] >= s.top().first))
        {
            while(s.size()>0 && a[i] >= s.top().first) s.pop();
            if(s.size()==0) v.push_back(-1);
            else v.push_back(s.top().second);
        }
        s.push({a[i],i});
    }
    for(int i=0;i<v.size();i++){
        // int temp = i - v[i];
        // v[i] = temp;
        v[i] = i - v[i];
    }
    return v;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    // vec ans = NLE(n, arr);
    // for (auto it : ans)
    //     cout << it << " ";
    vector<int> v = stockSpan(n,a);
    for(int i = 0 ;i < v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}