#include<bits/stdc++.h>
using namespace std;

void DFS(int node,vector<int>& vis,vector<int>adjL[])
{
    vis[node] = 1;
    cout<<node<<" ";
    for(auto it:adjL[node])
    {
        if(!vis[it])
        {
            DFS(it,vis,adjL);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adjList[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i=0;i<=n;i++)
    {
        cout<<i<<"{ ";
        for(auto it:adjList[i])
        {
            cout<<it<<" ";
        }
        cout<<"}"<<endl;
    }
    vector<int>vis(n+1,0);
    DFS(3,vis,adjList);
}