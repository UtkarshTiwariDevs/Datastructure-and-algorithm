/*
8 8                        
1 2
2 3   yes bipartie
2 7
3 4
4 5
5 6
5 8
6 7


*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef queue<int> que;

bool checkbfs(int i, vec adj[], int color[])
{
    que q;
    color[i] = 1;
    q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it:adj[node])
        {
            if(color[it] ==-1)
            {
                color[it] = 1 - color[node];
                q.push(it); 
            }
            else if(color[it] == color[node]) return false;
        }
    }
    return true;
}
bool bipartite(int n, vec adj[])
{
    int color[n];
    memset(color, -1, sizeof(color));

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!checkbfs(i, adj, color))
                return false;
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
    if (bipartite(n, adj))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
