#include<bits/stdc++.h>
using namespace std;
//max sum of non-adjacent elements
class sol{
    public:
        //tabulation
        int solve(vector<int> &nums, int i, vector<int> &dp){
        dp[0] = nums[0];
        int n = nums.size();
        int neg = 0;
        for(int i=1; i<n; i++){
            int pick= nums[i]; 
            if(i>1) pick+= dp[i-2];
            int notpick = dp[i-1] + 0;
            dp[i] = max(pick , notpick);
        }
        
        return dp[n-1];
    }
    int rob1(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n-1, dp);
    }

    //memoization
    int solve(vector<int> &nums, int i, vector<int> &dp){
        if(i==0) return nums[0];
        if(i<0) return 0;
        if(dp[i]!= -1) return dp[i];
        int pick= solve(nums, i-2, dp) + nums[i];
        int notpick = solve(nums, i-1, dp) + 0;

        return dp[i] = max(pick , notpick);
    }
    int rob2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n-1, dp);
    }
    
    //space optimized
    int rob3(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int notpick = 0 + prev;
            int curr = max(pick , notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
