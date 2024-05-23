#include<bits/stdc++.h>
using namespace std;

class distinctsubs{
public:
    //memoized
    int fun(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = fun(i-1,j-1,s,t,dp) +
        fun(i-1,j,s,t,dp);
        else return dp[i][j] = fun(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fun(n-1, m-1, s, t, dp);
    }
    //tabulation
    int subsequenceCounting(string &s1, string &s2, int n, int m) {
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<m+1;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            
            if(s1[i-1]==s2[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
} 

    //space optimized
    int subsequenceCounting(string &s1, string &s2, int n, int m) {
    vector<int> prev(m+1,0);
    prev[0]=1;
    
    for(int i=1;i<n+1;i++){
        for(int j=m;j>=1;j--){ 
            
            if(s1[i-1]==s2[j-1])
                prev[j] = (prev[j-1] + prev[j]);
            else
                prev[j] = prev[j]; 
        }
    }
    return prev[m];
} 
};