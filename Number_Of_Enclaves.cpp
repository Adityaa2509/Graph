#include<bits/stdc++.h>
using namespace std;

void DFS(int r,int c,vector<vector<bool>>&vis,vector<vector<int>>grid,int* del_row,int* del_col)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[r][c] = 1;
    for(int i=0;i<4;i++)
    {
        int nrow = r + del_row[i];
        int ncol = c + del_col[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            DFS(nrow,ncol,vis,grid,del_row,del_col);
        }
    }

    return ;

}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cin>>grid[i][j];
    }
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    int del_row[4] = {-1,0,1,0};
    int del_col[4] = {0,1,0,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i == 0 || i == n-1 || j == 0 || j == m-1)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                   DFS(i,j,vis,grid,del_row,del_col);
                }
            }
        }
    }
    int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])cnt++;
            }
        }
        cout<<cnt<<endl;
}