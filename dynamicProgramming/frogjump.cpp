#include<bits/stdc++.h>
using namespace std;
//recursion approach
int fun(int i, vector<int> &heights){
    if(i==0) return 0;
    int left= fun(i-1, heights) + abs(heights[i]-heights[i-1]);
    int right= INT_MAX;
    if(i>1){
        right= fun(i-2, heights) + abs(heights[i]-heights[i-2]);
    }
    return min(left, right);
}
int frogJump(int n, vector<int> &heights){
    return fun(n-1, heights);
}

//memoization method
int fun1(int i, vector<int> &heights, vector<int> &dp){
    if(i==0) return 0;
    if(dp[i]!= -1) return dp[i];
    int left= fun1(i-1, heights, dp) + abs(heights[i]-heights[i-1]);
    int right= INT_MAX;
    if(i>1){
        right= fun1(i-2, heights, dp) + abs(heights[i]-heights[i-2]);
    }
    return dp[i]= min(left, right);
}
int frogJump1(int n, vector<int> &heights){
    vector<int> dp(n+1, -1);
    return dp[n] = fun1(n-1, heights, dp);
}

//tabulation method
int frogJump2(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int fs= dp[i-1] + abs(heights[i]-heights[i-1]);
        int ss= INT_MAX;
        if(i>1) ss = dp[i-2] + abs(heights[i]-heights[i-2]);
        dp[i] = min(fs, ss);
    }
    return dp[n-1];
}

//space optimized
int frogJump3(int n, vector<int> &heights)
{
    int prev = 0;
    int prev2 = 0;
    for(int i=1; i<n; i++){
        int fs= prev + abs(heights[i]-heights[i-1]);
        int ss= INT_MAX;
        if(i>1) ss = prev2 + abs(heights[i]-heights[i-2]);
        int curr = min(fs, ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;
    
}