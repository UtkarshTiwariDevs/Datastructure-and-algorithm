#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vst, stack<int> &st, vector<int> adj[])
{
    vst[node] = 1;

    for (auto it : adj[node])
    {
        if (!vst[it])
            dfs(it, vst, st, adj);
    }
    st.push(node);
}

void revDFS(int node, vector<int> &vst, vector<int> transpose[])
{
    cout << node << " ";
    vst[node] = 1;
    for (auto it : transpose[node])
    {
        if(!vst[it])
            revDFS(it, vst, transpose);
    }
}
int main()
{
    // int n=6, m=7;
    int n,m;
    cin>>n>>m;
	vector<int> adj[n+1]; 
	// adj[1].push_back(3);
	// adj[2].push_back(1);
	// adj[3].push_back(2);
	// adj[3].push_back(5);
	// adj[4].push_back(6);
	// adj[5].push_back(4);
	// adj[6].push_back(5);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> vst(n+1, 0);

    for (int i = 0; i < n; i++)
        if (!vst[i])
            dfs(i, vst, st, adj);

    vector<int> transpose[n+1];
    for (int i = 0; i <= n; i++)
    {
        vst[i] = 0;
        for (auto it : adj[i])
            transpose[it].push_back(i);
    }

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vst[node])
        {
            cout << "SCC: \n";
            revDFS(node, vst, transpose);
            cout << endl;
        }
    }

    return 0;
}
