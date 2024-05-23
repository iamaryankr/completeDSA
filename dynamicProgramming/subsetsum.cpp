#include<bits/stdc++.h>
using namespace std;

class dponsubsequence{
public:
    //memoization
    bool f(int i, int target,vector<int> &arr, vector<vector<int>> &dp){
        if(target==0) return true;
        if(i==0) return (arr[0]==target);
        if(dp[i][target]!= -1) return dp[i][target];
        

        bool nottake = f(i-1, target, arr, dp);
        bool take = false;
        if(arr[i]<= target) take = f(i-1, target-arr[i],arr, dp);

        return dp[i][target] = take||nottake;
        }
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        return f(n-1, k,arr, dp);

}
    //tabulation
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    if(arr[0]<= k) dp[0][arr[0]] = true;
    for(int i=1; i<n; i++){
        for(int target=1; target<=k; target++){
            bool nottake = dp[i-1][target];
            bool take = false;
            if(arr[i]<= target) take = dp[i-1][target-arr[i]];
            dp[i][target] = take||nottake;
        }
    }
    return dp[n-1][k];

}
    //space optimized
    bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1,false);
    
    prev[0] = true;
    
    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    
    return prev[k];
}
};