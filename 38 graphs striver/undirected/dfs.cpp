#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;

void dfs(int node, vec &vis, vec adj[], vec &storeDFS)
{
    storeDFS.push_back(node);
    vis[node] = 1;

    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,storeDFS);
        }
    }
}
vec dfsOfGraph(int v, vec adj[])
{
    vec storesDFS;
    vec vis(v + 1, 0);

    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, storesDFS);
        }
    }
    return storesDFS;
}
int main()
{
    int v;
    cin >> v;
    vec adj[v+1]; 
    for (int i = 0; i < 7; i++) // total 6 edges
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(auto it : adj)
    {
        for(auto it1 : it)
        {
             cout<<it1<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    vec storeIt = dfsOfGraph(v,adj);
    for(int i=0;i<storeIt.size();i++)
        cout<<storeIt[i]<<" ";
    return 0;
}