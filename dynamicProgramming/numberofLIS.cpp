#include<bits/stdc++.h>
using namespace std;

class NumberofLIS{
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> ct(n,1);
        
        int maxi = 1;
        
        for(int i=0; i<=n-1; i++){
            for(int prev = 0; prev <=i-1; prev ++){
                
                if(nums[prev]<nums[i] 
                && dp[prev]+1>dp[i]){
                    dp[i] = dp[prev]+1;
                    ct[i] = ct[prev];
                }
                else if(nums[prev]<nums[i] 
                && dp[prev]+1==dp[i]){
                    ct[i] = ct[i] + ct[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        int nos =0;
        
        for(int i=0; i<=n-1; i++){
        if(dp[i]==maxi) nos+=ct[i];
        }
        
        return nos;
    }
};