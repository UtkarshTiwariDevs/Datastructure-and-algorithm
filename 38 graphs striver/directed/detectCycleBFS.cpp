#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vec;

void cycleKahn(int n,vec adj[])
{
    vec indegree(n,0);
    queue<int> q;

    for(int i=0;i<n;i++)
    {
        for(auto it : adj[i])
            indegree[it]++;
    }

    for(int i =0;i<n;i++)
        if(indegree[i] == 0) q.push(i);
    
    int count=0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it] ==0 ) q.push(it); 
        }
    }
    if(count == n) 
        cout<<"nop";
    else    
        cout<<"yep";
}
int main()
{
    int n,m;
    cin>>n>>m;

    vec adj[n];
    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    cycleKahn(n,adj);
    return 0;
}