#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int v, vector<int> adj[])
{
    vector<int> vst(v + 1, 0);
    vector<int> bfs;

    for (int i = 1; i<= v; i++)
    {
        if (!vst[i])
        {
            queue<int> q;
            vst[i] = 1;
            q.push(i);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adj[node])
                {
                    if (!vst[it])
                    {
                        q.push(it);
                        vst[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}
int main()
{
    int v ;
    cin>>v;
    vector<int> adj[v+1];
    for (int i = 0; i < 7; i++) //loop run for edges here total 6 edges
    {
        int u, y;
        cin >> u >> y;
        adj[u].push_back(y);
        adj[y].push_back(u);
    }
    // for(auto it : adj)
    // {
    //     for(auto it1 : it)
    //     {
    //         cout<<it1<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> ans = solve(v, adj);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}