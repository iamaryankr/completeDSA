#include<bits/stdc++.h>
using namespace std;

class partitionMAXsum{
public:
    //memoization
    int fun(int i, vector<int> &arr, int k, int n, vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!= -1) return dp[i];
        int len=0, sum=0, maxi=INT_MIN, maxAns=INT_MIN;
        for(int j=i; j<min(n, i+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            sum = maxi*len + fun(j+1, arr, k, n, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[i] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return fun(0, arr, k, n, dp);
    }
    //tabulation
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        
        for(int i=n-1; i>=0; i--){
            int len=0, sum=0, maxi=INT_MIN, maxAns=INT_MIN;
            for(int j=i; j<min(n, i+k); j++){
                len++;
                maxi = max(maxi, arr[j]);
                sum = maxi*len + dp[j+1];
                maxAns = max(maxAns, sum);
            }
            dp[i] = maxAns;
        }
        return dp[0];
    }
};