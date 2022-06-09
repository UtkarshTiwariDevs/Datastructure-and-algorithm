#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    int parent[n];
    int key[n];
    bool mst[n];
    for (int i = 0; i < n; i++)
        parent[i] = -1, key[i] = INT_MAX, mst[i] = false;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0}); // left 0 for wt and right 0 for index,we fill key in here

    for (int count = 0; count < n - 1; count++)
    {
        int u = pq.top().second;
        pq.pop();
        mst[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if (mst[v] == false && weight < key[v])
            {
                parent[v] = u;
                pq.push({key[v], v});
                key[v] = weight;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << parent[i] << "--" << i << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += key[i];
    cout << "sum ofm weight of MST :" << sum;
    return 0;
}