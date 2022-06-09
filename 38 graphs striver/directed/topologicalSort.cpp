#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef stack<int> st;

//dfs

void findTopo(int node,vec &vst,st &s,vec adj[])
{
    vst[node] = 1;

    for(auto it: adj[node])
    {
        if(vst[it] == 0)
        {
            findTopo(it,vst,s,adj);
        }
    }
    s.push(node);
}
vector<int> topoSort(int n,vec adj[])
{
    st s;
    vec vst(n,0);

    for(int i =0;i<n;i++)
    {
        if(vst[i] == 0)
            findTopo(i,vst,s,adj);
    }
    vec topo;
    while(!s.empty())
    {
        topo.push_back(s.top());
        s.pop();
    }
    return topo;
}
int main(){
    int n , m;  // n,m nodes and edge rescp
    cin>>n>>m;
    vec adj[n];
    for(int i=0;i<m;i++)
    {
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    // for(auto it : adj)
    // {
    //     for(auto it1 : it)
    //         cout<<it1<<" ";
    //     cout<<endl;
    // }
    vec topo = topoSort(n,adj);
    for(auto it : topo)
        cout<<it<<" ";
    return 0;
}