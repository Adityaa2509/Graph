#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src,vector<bool>&vis,vector<int>adjL[])
{
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second; 
        q.pop();
        vis[node] = 1;
        for(auto it : adjL[node])
        {
            if(!vis[it])q.push({it,node});
            else if(parent != it)return true;
        }
    }
    return false;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adjL[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjL[u].push_back(v);        
        adjL[v].push_back(u);
    }
    vector<bool>vis(n+1,0);
    bool cycle = false;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(isCycle(i,vis,adjL))cycle = true;
        }
    }
    if(cycle)cout<<"Present"<<endl;
    else cout<<"Absent"<<endl;
}