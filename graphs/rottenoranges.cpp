#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        int delrow[] = {1,0,-1,0};
        int delcol[] = {0,1,0,-1};
        int ans = 0;
        while(!q.empty()){
            int row = q.front().first.first; 
            int col = q.front().first.second;
            int t = q.front().second;
            ans = max(ans,t);
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    grid[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m ;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};