#include<bits/stdc++.h>
using namespace std;

class dponPartition{
public:
    //memoization
    int fun(int i, int j, int N, int *arr, vector<vector<int>> &dp){
        if(i==j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini= INT_MAX;
        for(int k=i; k<j; k++){
            int steps = arr[i-1]*arr[k]*arr[j] + 
            fun(i, k, N, arr, dp) + fun(k+1, j, N, arr, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>> dp(N, vector<int> (N, -1));
        return fun(1, N-1, N, arr, dp);
    }
    //tabulation
    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>> dp(N, vector<int> (N));
        for(int i=1; i<N; i++){
            dp[i][i] = 0;
        }
      
        for(int i=N-1; i>=1; i--){
            for(int j=i+1; j<N; j++){
                int mini = INT_MAX;
                for(int k=i; k<j; k++){
                    int steps = arr[i-1]*arr[k]*arr[j] + 
                    dp[i][k] + dp[k+1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N-1];
    }
};