#include <bits/stdc++.h>
using namespace std;

void disBFS(int n, int src, vector<int> adj[])
{
    int dis[n];
    queue<int> q;
    
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dis[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (dis[node] + 1 < dis[it])
            {
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << dis[i] << " ";
}
int main()
{
    int n, m, src;
    cin >> n >> m >> src;
    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    disBFS(n, src, adj);
    return 0;
}