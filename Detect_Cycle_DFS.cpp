#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src,int parents,vector<bool>&vis,vector<int>adjL[])
{
  vis[src] = 1;
  for(auto it : adjL[src])
  {
    if(!vis[it])
    {
        if(isCycle(it,src,vis,adjL))return true;
        else if(it!=parents)return true;
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
            if(isCycle(i,-1,vis,adjL))cycle = true;
        }
    }
    if(cycle)cout<<"Present"<<endl;
    else cout<<"Absent"<<endl;
}