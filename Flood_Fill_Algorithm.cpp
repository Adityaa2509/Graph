#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>&vis,int r,int c,int color,vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int temp = grid[r][c];
    vis[r][c] = 1;
    grid[r][c] = color;
    int del_row[4] = {0,-1,0,1};
    int del_col[4] = {-1,0,1,0};
    for(int i=0;i<4;i++)
    {
        int nrow = r+del_row[i];
        int ncol = c+del_col[i];
    if((nrow>=0&&nrow<n)&&(ncol>=0&&ncol<m)&&(!vis[nrow][ncol])&&(grid[nrow][ncol] == temp))
    {
        DFS(vis,nrow,ncol,color,grid);
    }
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cin>>grid[i][j];
    }
    int sr,sc,color;
    cout<<"Enter source row and source col"<<endl;
    cin>>sr>>sc;
    cout<<"Enter color"<<endl;
    cin>>color;

    vector<vector<int>>vis(n,vector<int>(m,0));

    int prev = grid[sr][sc];
    int del_row[4] = {0,-1,0,1};
    int del_col[4] = {-1,0,1,0};
    grid[sr][sc] = color;
    for(int i=0;i<4;i++)
    {
        int nrow = sr+del_row[i];
        int ncol = sc+del_col[i];
    if((nrow>=0&&nrow<n)&&(ncol>=0&&ncol<m)&&(!vis[nrow][ncol])&&(grid[nrow][ncol] == prev))
    {
        DFS(vis,nrow,ncol,color,grid);
    }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cout<<grid[i][j]<<" ";
        cout<<endl;
    }    

}