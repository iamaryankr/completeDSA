#include<bits/stdc++.h>
using namespace std;

class UniquePaths{
public:
    //memoized
    int fun(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int up = fun(i-1, j, m, n, dp);
        int left = fun(i, j-1, m, n, dp);
        return dp[i][j] = left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return dp[m-1][n-1] = fun(m-1, n-1, m, n, dp);
    }

    //tabulation
    int uniquePaths2(int m, int n) {
        int dp[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[i][j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    //space optimized
    int uniquePaths3(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0; i<m; i++){
            vector<int> temp(n,0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0) temp[j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = temp[j-1];
                    temp[j] = up+left;
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }

};
 

