#include<bits/stdc++.h>
using namespace std;

class minpathsum{
public:
    //memoization
    int fun(int i, int j, vector<vector<int>>& grid,
    vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!= -1) return dp[i][j];
        int up = grid[i][j] + fun(i-1, j, grid, dp);
        int left = grid[i][j] + fun(i, j-1, grid, dp);

        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (m,-1));
        return fun(m-1, n-1, grid, dp);
    } 

    //tabulation
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (m));
        dp[0][0] = grid[0][0];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) continue;
                int up = 0;
                int left = 0;
                if(i>0) up = dp[i-1][j] + grid[i][j];
                if(j>0) left = dp[i][j-1] + grid[i][j];
                dp[i][j] = min(up, left);
            }
        }
        return dp[m-1][n-1];
    } 
};