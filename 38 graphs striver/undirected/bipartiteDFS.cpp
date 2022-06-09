#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vec;

bool checkDFS(int node,vec adj[],int color[])
{
    if(color[node]==-1) color[node] = 1;
    
    for(auto it : adj[node])
    {
        if(color[it] == -1)
        {
            color[it] = 1 -color[node];
            if(!checkDFS(it,adj,color))
                return false;
            else if(color[it] == color[node]) return false;
        }
    }
    return true;
}
bool bipartite(int n,vec adj[])
{
    int color[n];
    memset(color,-1,sizeof(color));

    for(int i =0;i<n;i++)
    {
        if(color[i] ==-1)
        {
            if(!checkDFS(i,adj,color)) return false;
        }
    }
    return true;
}
int main()
{
     int n, m; // n,m = no. of nodes and edges resp
    cin >> n >> m;

    vec adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(bipartite(n,adj))
        cout<<"Yes";
    else
        cout<<"No"; 
    return 0;
}