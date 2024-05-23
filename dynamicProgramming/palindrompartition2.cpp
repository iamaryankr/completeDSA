#include<bits/stdc++.h>
using namespace std;

class dppalindrome2{
public:
    //memoized
    bool isPalindrome(int i, int j, string &s){
        while(j>i){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int fun(int i, string &s, int n, vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!= -1) return dp[i];
        int mincost = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalindrome(i, j, s)){
                int cost = 1 + fun(j+1, s, n, dp);
                mincost = min(mincost, cost);
            }
        }
        return dp[i] = mincost;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return fun(0, s, n, dp)-1;
    }
    //tabulation
    int minCut(string str) {
        int n = str.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            //string[i...j]
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, str)) {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};