#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int adjMat[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)adjMat[i][j]=0;
       
    }
    int dir;
    cin>>dir;
    for(int i=0;i<m;i++)
    {  
        int u,v;
        cin>>u>>v;
        adjMat[u][v] = 1;
        if(dir ==0)adjMat[v][u] = 1;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)cout<<adjMat[i][j]<<" ";
        cout<<endl;
    }
}