#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,src;
    cin>>n>>m>>src;
    vector<pair<int,int>> adj[n+1];

    for(int i = 0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(n+1,INT_MAX);
    dis[src] = 0 ;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        // vector<pair<int,int>> :: iterator it;
        for(auto it : adj[prev])
        {
            int next = it.first;
            int nextDist = it.second;
            if(dis[next] > dist + nextDist)
            {
                dis[next] = dist + nextDist;
                pq.push(make_pair(dis[next],next));
            }
        }
    }

    cout<<"The dis from source "<<src<<":\n";
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    return 0;
}