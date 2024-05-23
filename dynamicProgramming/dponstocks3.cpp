#include<bits/stdc++.h>
using namespace std;

class dponstock3{
public:
    //memoized
    int fun(int i, int buy, int cap, vector<int> &prices, int n, 
    vector<vector<vector<int>>> &dp){
        if(i==n) return 0;
        if(cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        if(buy){
            return dp[i][buy][cap] = max(fun(i+1,0,cap, prices, n, dp)-prices[i] 
            ,fun(i+1, 1, cap, prices, n, dp));
        }
        else
            return dp[i][buy][cap] = max(fun(i+1, 1, cap-1,prices,n,dp)+prices[i] 
            ,fun(i+1, 0, cap, prices, n, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, 
        vector<vector<int>> (2, vector<int> (3, -1)));
        return fun(0, 1, 2, prices, n, dp);
    }
    //tabulation
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, 
        vector<vector<int>> (2, vector<int> (3, 0)));
        for(int i=0 ;i<n-1; i++){
            for(int buy=0; buy<=1; buy++){
                dp[i][buy][0] = 0;
            }
        }
        for(int buy=0; buy<=1; buy++){
            for(int cap=0; cap<=2; cap++){
                dp[0][buy][cap] = 0;
            }
        }

        for(int i=n-1 ;i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy){
                        dp[i][buy][cap] = max(dp[i+1][0][cap]
                        -prices[i] , dp[i+1][1][cap]);
                    }
                    else
                        dp[i][buy][cap] = max(dp[i+1][1][cap-1]
                        +prices[i] , dp[i+1][0][cap]);
                 }
            }
        }
        return dp[0][1][2];
        
    }
    //space optimized
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2,vector<int> (3,0));
        vector<vector<int>> cur(2,vector<int> (3,0));
        
        
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    
                    if(buy==0){
                        cur[buy][cap] = max(0+ahead[0][cap], 
                                    -prices[ind] + ahead[1][cap]);
                    }
        
                    if(buy==1){
                        cur[buy][cap] = max(0+ahead[1][cap],
                                    prices[ind] + ahead[0][cap-1]);
                    }
                }
            }
            ahead = cur;
        }
        
        return ahead[0][2];
        
    }
};