#include<bits/stdc++.h>
using namespace std;

class partitionwithgivendiff{
public:
     //0 is included in the array
    int fun(int i, int target, vector<int> &nums,
    vector<vector<int>> &dp){
        if(i==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || nums[0]==target) return 1;
            return 0;
        }
        if(dp[i][target]!= -1) return dp[i][target];
        int nottake = fun(i-1, target, nums, dp);
        int take = 0;
        if(nums[i]<=target) take = fun(i-1, target-nums[i], nums, dp);
        
        return dp[i][target] = take + nottake;
    }
    int findways(vector<int> &nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return fun(n-1, target, nums, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto it: nums) sum += it;
        if(sum-target < 0 || (sum - target)%2) return false;

        return findways(nums, (sum-target)/2);
    }

    //using tabulation
    int findWays(vector<int> &num, int tar){
    int n = num.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken);
        }
    }
    return dp[n-1][tar];
    }

    int countPartitions(int n, int d, vector<int>& arr){
        int totSum = 0;
        for(int i=0; i<n;i++){
            totSum += arr[i];
        }
        
        if(totSum-d <0 || (totSum-d)%2 ) return 0;
        
        return findWays(arr,(totSum-d)/2);
    }
  
};