//kahn algo
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef queue<int> qu;
vector<int> topoSort(int n,vec adj[])
{
    vec topoAns;
    qu q;
    vec indegree(n,0);
    
    for(int i=0;i<n;i++)
        for(auto it : adj[i]) indegree[it]++;


    for(int i =0 ;i<n;i++)
        if(indegree[i] == 0) q.push(i);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topoAns.push_back(node);

        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it] ==0) q.push(it);
        }
    }
    return topoAns;
}
int main(){
    int n,m;
    cin>>n>>m;

    vec adj[n];
    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vec topoAns = topoSort(n,adj);
    for(auto it: topoAns)
        cout<<it<<" ";    
    return 0;
}