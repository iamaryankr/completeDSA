#include<bits/stdc++.h>
using namespace std;

//distance of nearest 1
//bfs
class solution{
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int n = mat.size(); int m = mat[0].size();
            vector<vector<int>> ans(n, vector<int> (m,0));
            vector<vector<int>> vis(n, vector<int> (m,0));
            queue<pair<pair<int,int>,int>> q;

            for(int i=0 ;i<n ;i++){
                for(int j=0 ;j<m ;j++){
                    if(mat[i][j]==1){
                        q.push({{i,j},0});
                        vis[i][j]= 1;
                    }
                    else vis[i][j]= 0;  
                }
            }
            int delrow[]= {-1,0,1,0};
            int delcol[]= {0,1,0,-1};

            while(!q.empty()){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int steps = q.front().second;
                q.pop();
                ans[row][col] = steps;
                
                for(int i=0; i<4; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(ncol>=0 && ncol<m && nrow>=0 && nrow<n &&
                    vis[nrow][ncol]==0){
                        vis[nrow][ncol]=1;
                        q.push({{nrow,ncol}, steps+1});
                    }
                }

            }
            return ans;
    }
};

//dfs
class Solution {
public:
    void dfs(vector<vector<int>>& mat, vector<vector<int>>& ans, int row, int col, int dist) {
        if (row<0 || row>=mat.size() || col<0 || 
        col>=mat[0].size() || dist>=ans[row][col]) {
            return;
        }     
        ans[row][col] = dist;      
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};    
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            dfs(mat, ans, newRow, newCol, dist + 1);
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();    
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));  
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dfs(mat, ans, i, j, 0);
                }
            }
        }    
        return ans;
    }
};
