#include<bits/stdc++.h>
using namespace std;

class zerooneknapsack{
public:
    //memoized code
    int fun(int i, int W, int wt[], int val[], vector<vector<int>> &dp){
        if(i==0){
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        if(dp[i][W] != -1) return dp[i][W];
        int nottake = 0 + fun(i-1, W, wt, val, dp);
        int take = INT_MIN;
        if(wt[i]<= W) take = val[i] + fun(i-1, W-wt[i], wt, val, dp);
        
        return dp[i][W] = max(take , nottake);
    }
    int knapSack(int W, int wt[], int val[], int n) { 
        vector<vector<int>> dp(n, vector<int> (W+1 , -1));
        return fun(n-1, W, wt, val, dp);
    }

    //tabulation code
    int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
 }

    //space optimized to the most
    //single row optimisation
    int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<int> prev(W+1,0);
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=W; cap>=0; cap--){
            
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            prev[cap] = max(notTaken, taken);
        }
    }
    
    return prev[W];
}
};

//unbounded knapsac
//infinite supply of coins
int fun(int i, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(i==0){
        return (w/weight[0])*profit[0];
    }
    if(dp[i][w]!=-1) return dp[i][w];
    int nottake = 0 + fun(i-1, w, profit, weight, dp);
    int take = -1e9;
    if(w>= weight[i]) take = profit[i] + fun(i, w-weight[i], profit, weight, dp);

    return dp[i][w] = max(take, nottake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int> (w+1, -1));
    return fun(n-1, w, profit, weight, dp);
}