#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;

void dfs(int node, int parent, vec &vst, vec &tin, vec &low, int &timer, vec adj[])
{
    vst[node] = 1;
    tin[node] = low[node] = timer++;

    for(auto it : adj[node])
    {
        if(it == parent) 
            continue;
        if(!vst[it])
        {
            dfs(it,node,vst,tin,low,timer,adj);
            low[node] = min(low[node] , low[it]);
            if(low[it] > tin[node])
                cout<<node <<"-"<<it<<endl;
        }
        else   
            low[node] = min(low[node] , tin[it]);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vec adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vec vst(n,0);
    vec tin(n,-1);
    vec low(n,-1);
    int timer = 0;
    

    for (int i = 0; i <= n; i++)
    {
        if (!vst[i])
            dfs(i, -1, vst, tin, low, timer, adj);
    }

    return 0;
}