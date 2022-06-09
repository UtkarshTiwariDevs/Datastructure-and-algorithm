#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

void dfs(int node, int parent, vec &vst, vec &tin, vec &low, int &timer, vec adj[], vec &arti)
{
    vst[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vst[it])
        {
            dfs(it, node, vst, tin, low, timer, adj, arti);
            low[node] = min(low[it], low[node]);
            if (low[it] >= tin[node] && parent != -1)
                arti[node] = 1;
        }
        else
            low[node] = min(low[node], tin[it]);
    }
    if (parent == -1 && child > 1)
        arti[node] = 1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vec adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for (auto it : adj)
    // {
    //     for (auto it1 : it)
    //         cout << it1 << " ";
    //     cout << endl;
    // }

    vec vst(n+1, 0);
    vec tin(n+1, -1);
    vec low(n+1, -1);
    int timer = 0;
    vec arti(n+1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!vst[i])
            dfs(i, -1, vst, tin, low, timer, adj, arti);
    }

    for (int i = 0; i <= n; i++)
        if (arti[i] == 1)
            cout << i << " ";
    return 0;
}