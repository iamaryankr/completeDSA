#include<bits/stdc++.h>
using namespace std;

class dponstring{
public:
    int fun(int i, int j, string text1, string text2, 
    vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        if(text1[i]==text2[j]) return 1+fun(i-1, j-1, text1, text2, dp);
        return dp[i][j] = max(fun(i-1, j, text1, text2, dp),
        fun(i, j-1, text1, text2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fun(n-1, m-1, text1, text2, dp);
    }

    //tabulation after shifting index
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 0;       
        for(int j=0; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m ;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }  
        return dp[n][m];
    }

    //space optiimized
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector<int> prev(n+1, 0), curr(m+1, 0);
        for(int i=0; i<=m; i++) prev[i] = 0;       

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m ;j++){
                if(text1[i-1]==text2[j-1]) curr[j] = 1+prev[j-1];
                else curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }  
        return prev[m];
    }
};

//printing lcs

string longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 0;       
        for(int j=0; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m ;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }  
        
        int len = dp[n][m];
        string s = "";
        for(int i=0; i<len; i++) s += '#';

        int i = n, j = m;  
        int index = len-1;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                s[index] = text1[i-1];
                index--;
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i = i-1;
            }
            else{
                j = j-1;
            }
        }
        return s;
    }

