#include<bits/stdc++.h>
using namespace std;

class MINfallingpath{
public:
    //using memoization
    int fun(int i, int j, int n, vector<vector<int>>& matrix,
    vector<vector<int>> &dp){
        if(j<0 || j>=n) return 1e8;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!= -1) return dp[i][j];

        int up = matrix[i][j] + fun(i-1, j, n, matrix, dp);
        int dleft = matrix[i][j] + fun(i-1, j-1, n, matrix, dp);
        int dright = matrix[i][j] + fun(i-1, j+1, n, matrix, dp);

        return dp[i][j] = min(up, min(dleft, dright));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int ans = 1e8;
        for(int i=0; i<n; i++){
            ans = min(ans, fun(n-1, i, n, matrix, dp));
        }
        return ans;
    }

    //using tabulation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n));
        int ans = 1e8;
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int dleft = 1e8, dright = 1e8;
                if(j-1>=0) dleft = matrix[i][j] + dp[i-1][j-1];
                if(j+1<n) dright = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min(up, min(dleft, dright));
            }
        }
        for(int j=0; j<n; j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};