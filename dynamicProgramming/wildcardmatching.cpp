#include<bits/stdc++.h>
using namespace std;

class wcm{
public:
    //memoized
    bool fun(int i, int j, string &s1, string &s2,
    vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0){
            for(int ii=0; ii<i; ii++){
                if(s1[ii] != '*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i] == s2[j] || s1[i]=='?') return dp[i][j] = 
        fun(i-1, j-1, s1, s2,dp);
        if(s1[i]=='*') return dp[i][j] = fun(i-1, j, s1, s2,dp) | 
        fun(i,j-1, s1, s2,dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fun(n-1, m-1, p, s, dp);
    }
    //tabulated
     bool isAllStars(string & S1, int i) {
        for (int j = 1; j <= i; j++) {
            if (S1[j - 1] != '*')
            return false;
        }
        return true;
}
    bool isMatch(string S2, string S1) {
        int n = S1.size();
        int m = S2.size();

        vector < vector < bool >> dp(n + 1, vector < bool > (m, false));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++) dp[0][j] = false;
        for (int i = 1; i <= n; i++) dp[i][0] = isAllStars(S1, i);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];

            else {
                if (S1[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

                else dp[i][j] = false;
            }
            }
        }

        return dp[n][m];
    }
};