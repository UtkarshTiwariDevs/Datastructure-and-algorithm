#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int, int>> vec;
void topoSort(int node, stack<int> &st, int vst[], vec adj[])
{
    vst[node] = 1;

    for (auto it : adj[node])
    {
        if (vst[it.first] == 0)
            topoSort(it.first, st, vst, adj);
    }
    st.push(node);
}
void shorPath(int n, int src, vec adj[])
{
    int vst[n] = {0};
    stack<int> st;
    for (int i = 0; i < n; i++)
        if (vst[i] == 0)
            topoSort(i, st, vst, adj);

    int dis[n];
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dis[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if (dis[node] + it.second < dis[it.first])
                    dis[it.first] = dis[node] + it.second;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dis[i] == INT_MAX)
            cout << "INF";
        else
            cout<<dis[i]<<" ";
    }
}
int main()
{
    int n, m, src;
    cin >> n >> m >> src;
    vec adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    shorPath(n,src,adj);
    return 0;
}