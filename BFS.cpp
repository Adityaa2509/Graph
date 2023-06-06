#include<bits/stdc++.h>
using namespace std;
void BFS(vector<int>adjList[],int n)
{
    queue<int>q;
    q.push(1);
    bool vis[n+1] = {0};
    vis[1] = 1;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto it : adjList[temp])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adjList[n+1];
    int dir;
    cin>>dir;
    for(int i=0;i<m;i++)
    {  
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        if(dir ==0)adjList[v].push_back(u);
    }
   BFS(adjList,n);
}