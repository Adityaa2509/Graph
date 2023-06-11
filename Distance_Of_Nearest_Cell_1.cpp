#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    queue<pair<pair<int,int>,int>>q;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    vector<vector<int>>op(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 0)
            {
                q.push({{i,j},0});
                vis[i][j] = 1;
            
            }
        }
    }
    int del_row[4] = {-1,0,1,0};
    int del_col[4] = {0,1,0,-1};
    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        op[r][c] = dist;
        for(int i=0;i<4;i++)
        {
            int nrow = r + del_row[i];
            int ncol = c + del_col[i];
            if((nrow>=0&&nrow<n)&&(ncol>=0&&ncol<m)&&!vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow,ncol},dist+1});
            }
        }

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cout<<op[i][j]<<" ";
        cout<<endl;
    }
}