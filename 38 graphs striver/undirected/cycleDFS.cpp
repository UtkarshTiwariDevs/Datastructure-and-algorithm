#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
bool checkCycle(int node,int parent,vec &vst,vec adj[])
{
    vst[node] =1;
    for(auto it : adj[node])
    {
        if(!vst[it])
            if(checkCycle(it,node,vst,adj)) return true;
        else if(it != parent)
            return true;
    }
    return false;
}
bool checkDFS(int v,vec adj[])
{
    vec vst(v+1,0);

    for(int i= 1;i<=8;i++)
    {
        if(!vst[i])
        {
            if(checkCycle(i,-1,vst,adj)) return true;
        }
    }
    return false;
}
int main(){
    int v;
    cin>>v;
    vec adj[v+1];

    for(int i =0 ;i<7;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // for(auto it : adj)
    // {
    //     for(auto it1 : it)
    //         cout<<it1<<" ";
    //     cout<<endl;
    // }
    if(checkDFS)
        cout<<"Cycle Detected";
    else
        cout<<"No cycle detected";
    return 0;
}
