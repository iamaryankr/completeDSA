#include<bits/stdc++.h>
using namespace std;

//case of infinite supply
class Mincoins{
public:
    //memoization
    int fun(int i, int amount, vector<int> &coins,
    vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[i]==0) return amount/coins[i];
            else return 1e9;
        }
        if(dp[i][amount]!= -1) return dp[i][amount];
        int nottake = 0 + fun(i-1, amount, coins, dp);
        int take = INT_MAX;
        if(amount>=coins[i]) take = 1 + fun(i, amount-coins[i], coins, dp);

        return dp[i][amount] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = fun(n-1, amount, coins, dp);
        if(ans>=1e9) return -1;
        return ans;
    }

    //tabulation
    int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}

    //space optimized
    int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<int> prev(T+1,0), cur(T+1,0);
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + cur[target - arr[ind]];
                
             cur[target] = min(notTake, take);
        }
        prev = cur;
    }
    
    int ans = prev[T];
    if(ans >=1e9) return -1;
    return ans;
}

};