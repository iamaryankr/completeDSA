#include<bits/stdc++.h>
using namespace std;

class dponstocks{
public:
     //memoized
    int fun(int i, int buy, vector<int>& arr, int n, 
    vector<vector<int>> &dp){
        if(i==n) return 0;
        int profit = 0;
        if(dp[i][buy]!= -1) return dp[i][buy];
        if(buy){
            profit = max(fun(i+1, 0, arr, n, dp)-arr[i], 
            fun(i+1, 1, arr, n, dp) );
        }
        else{
            profit = max(fun(i+1, 1, arr, n, dp)+arr[i], 
            fun(i+1, 0, arr, n, dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return fun(0, 1, prices, n, dp);
    }

    //tabulation
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        
        dp[n][0] = dp[n][1] = 0;
        int profit = 0;
        for(int i= n-1; i>=0 ;i--){
            for(int buy= 0; buy<=1; buy++){
                if(buy){
                    profit = max(dp[i+1][0]-prices[i], dp[i+1][1]);
                }
                else{
                    profit = max(dp[i+1][1]+prices[i], dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return profit;
    }
    //space optimized
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);
        
        curr[0] = curr[1] = 0;
        int profit = 0;
        for(int i= n-1; i>=0 ;i--){
            for(int buy= 0; buy<=1; buy++){
                if(buy){
                    profit = max(ahead[0]-prices[i], ahead[1]);
                }
                else{
                    profit = max(ahead[1]+prices[i], ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};