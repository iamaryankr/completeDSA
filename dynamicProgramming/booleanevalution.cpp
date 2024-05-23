#include<bits/stdc++.h>
using namespace std;

class BooleanEvaluationtotrue{
public:
    #define ll long long
    int mod = 1003;

    int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
        //Base case 1:
        if (i > j) return 0;
        //Base case 2:
        if (i == j) {
            if (isTrue == 1) return exp[i] == 'T';
            else return exp[i] == 'F';
        }
    
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        ll ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind += 2) {
            ll lT = f(i, ind - 1, 1, exp, dp);
            ll lF = f(i, ind - 1, 0, exp, dp);
            ll rT = f(ind + 1, j, 1, exp, dp);
            ll rF = f(ind + 1, j, 0, exp, dp);
    
            if (exp[ind] == '&') {
                if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
            }
            else if (exp[ind] == '|') {
                if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                else ways = (ways + (lF * rF) % mod) % mod;
            }
            else {
                if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int countWays(int N, string S){
        // code here
        vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(2, -1)));
        return f(0, N - 1, 1, S, dp);
    }
};