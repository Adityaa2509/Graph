#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<char>>grid,vector<vector<int>>& vis,int i,int j)
{
    int n= grid.size();
    int m = grid[0].size();
    queue<pair<int,int>>q;
    q.push({i,j});
    int del_row[4]= {0,-1,0,1};
    int del_col[4]= {-1,0,1,0};
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        int r = temp.first;
        int c = temp.second;
        vis[r][c] = 1;
        for(int k=0;k<4;k++)
        {
            int nrow = r+del_row[k];
            int ncol = c+del_col[k];
            if((nrow>=0 && nrow<n)&&(ncol>=0&&ncol<m)&&(!vis[nrow][ncol])&&grid[nrow][ncol] == '1')
            q.push({nrow,ncol});
        }

    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>grid[i][j];
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1'&&!vis[i][j])
            {
            BFS(grid,vis,i,j);
            cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}