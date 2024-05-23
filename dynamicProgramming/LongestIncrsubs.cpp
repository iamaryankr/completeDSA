#include<bits/stdc++.h>
using namespace std;

class dponLIS{
public:
    //memoization //with index shifting(prev+1)
    int fun(int i, int prev, vector<int> &nums, int n
    , vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int nottake = 0 + fun(i+1, prev, nums, n, dp);
        int take = INT_MIN;
        if(prev==-1 || nums[i]>nums[prev]){
            take = 1 + fun(i+1, i, nums, n, dp);
        }
        return dp[i][prev+1] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return fun(0, -1, nums, n, dp);
    }

    //tabulation //with index shifting(prev+1)
    int lenghtofLIS(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int prev = i-1; prev>=-1; prev--){
                int nottake = 0 + dp[i+1][prev+1];
                int take = INT_MIN;
                if(prev==-1 || nums[i]>nums[prev]){
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][prev+1] = max(take, nottake);
            }
        }
        return dp[0][-1+1];
    }

    //special tabulation method
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for(int i=0 ;i<n; i++){
            for(int prev= 0; prev<i; prev++){
                if (nums[prev] < nums[i]){
                    dp[i] = max(dp[i], 1+dp[prev]);
                }
            }
        }
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};