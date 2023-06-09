#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int>& vis,int node,vector<int>adjL[])
{
    queue<int>q;
    q.push(node);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        vis[temp] = 1;
        for(auto it : adjL[temp])
        {
            if(!vis[it])
            q.push(it);
        }

    }
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
    vector<int>vis(n+1,0);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        
        if(!vis[i])
        {
            cnt++;
            BFS(vis,i,adjL);
        
        }
    }
    cout<<cnt<<endl;
}