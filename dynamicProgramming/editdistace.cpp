#include<bits/stdc++.h>
using namespace std;

class editdistance{
public:
    //memoized
    int fun(int i, int j ,string &s1, string &s2, 
    vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!= -1) return dp[i][j];
        
        if(s1[i]==s2[j]) return dp[i][j]= 0+ fun(i-1, j-1, s1, s2, dp);
        int del = 1 + fun(i-1, j, s1, s2, dp);
        int insert = 1 + fun(i, j-1, s1, s2, dp);
        int replace = 1 + fun(i-1, j-1, s1, s2, dp);

        return dp[i][j] = min(del, min(insert, replace));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fun(n-1 ,m-1, word1, word2, dp);
    }

    //tabulation
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;

        for(int i=1; i<=n ;i++){
            for(int j=1; j<=m ;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]= dp[i-1][j-1];
                else{
                    int del = 1 + dp[i-1][j];
                    int insert = 1 + dp[i][j-1];
                    int replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min(del, min(insert, replace));
                }
            } 
        }
        return dp[n][m];
    }

    //space optimized
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(n+1, 0), curr(m+1, 0);
        for(int j=0; j<=m; j++) prev[j] = j;

        for(int i=1; i<=n ;i++){
            curr[0] = i;
            for(int j=1; j<=m ;j++){
                if(word1[i-1]==word2[j-1]) curr[j]= prev[j-1];
                else{
                    int del = 1 + prev[j];
                    int insert = 1 + curr[j-1];
                    int replace = 1 + prev[j-1];

                    curr[j] = min(del, min(insert, replace));
                }
               
            } 
            prev = curr;
        }
        return prev[m];
    }
};