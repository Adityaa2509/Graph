#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>mat(n,vector<char>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>mat[i][j];
    }

    vector<vector<bool>>vis(n,vector<bool>(m,0));

    queue<pair<int,int>>q;

    for(int i=0;i<m;i++)
    {
        //first row
        if(mat[0][i] == 'O' && !vis[0][i])
        {
            vis[0][i] = 1;;
            q.push({0,1});

        }
        //last row
        if(mat[n-1][i] == 'O' && !vis[n-1][i])
        {
            vis[n-1][i] = 1;
            q.push({n-1,i});
        }

    }   
for(int i=0;i<n;i++)
{
    //first column
    if(mat[i][0] == 'O' && !vis[i][0])
    {
        vis[i][0] = 1;
        q.push({i,0});
    }
    if(mat[m-1][i] == 'O' && !vis[m-1][0])
    {
        vis[m-1][0] = 1;
        q.push({m-1,i});
    }

}

int del_row[4] = {-1,0,1,0};
int del_col[4] = {0,1,0,-1};

while(!q.empty())
{
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    for(int i=0;i<4;i++)
    {
        int nrow = r+del_row[i];
        int ncol = c+del_col[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&mat[nrow][ncol]=='0' &&!vis[nrow][ncol])
        {
            vis[nrow][ncol] = 1;
            q.push({nrow,ncol});
        }
    }

}

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j] =='O'&& !vis[i][j])
            mat[i][j] = 'X';
        }
    }



    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout<<mat[i][j]<<" ";
        cout<<endl;
    }



}