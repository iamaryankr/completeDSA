#include<bits/stdc++.h>
using namespace std;

class coinchange2{
public:
    //memoized
    int fun(int i, int amount, vector<int>& coins,
    vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[i]==0) return 1;
            return 0;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int nottake = fun(i-1, amount, coins, dp);
        int take = 0;
        if(amount>=coins[i]) take = fun(i, amount-coins[i], coins, dp);

        return dp[i][amount] = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return fun(n-1, amount, coins, dp);
    }

    //tabulation
     int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for(int t=0; t<=amount; t++){
            if(t%coins[0]==0) dp[0][t] = 1;
            else dp[0][t] = 0;
        }
        for(int i=1; i<n ;i++){
            for(int t=0 ;t<=amount; t++){
                int nottake = dp[i-1][t];
                int take = 0;
                if(t>=coins[i]) take = dp[i][t-coins[i]];

                dp[i][t] = take + nottake;
            }
        }
        return dp[n-1][amount];
    }
};