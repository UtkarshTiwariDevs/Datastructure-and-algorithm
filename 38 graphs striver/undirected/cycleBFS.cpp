#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef queue<pair<int, int>> qp;

bool checkCycle(int i, int v, vec adj[], vec &vis)
{
    qp q;
    vis[i] = 1;
    q.push({i, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;

        q.pop();
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it] =1;
                q.push({it,node});
            }
            else if(par != it)
                return true;
        }
    }
    return false;
}
bool isCycle(int v, vec adj[])
{
    vec vis(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
            if (checkCycle(i, v, adj, vis))
                return true;
    }
    return false;
}
int main()
{
    int v;
    cin >> v;
    vector<int> adj[v + 1];
    for (int i = 0; i < 10; i++) // loop run for edges here total 10 edges
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (auto it : adj)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    cout << endl;

    if (isCycle)
        cout << "Cyclic";
    else
        cout << "Not Cyclic";
    return 0;
}