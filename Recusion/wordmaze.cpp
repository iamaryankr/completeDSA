<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[301];
    bool func(string &s, set<string> &st, int i){
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j=i; j<s.size(); j++){
            temp+=s[j];
            if(st.find(temp) != st.end()){
                if(func(s, st, j+1)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp, -1, sizeof dp);
        for(auto it:wordDict) st.insert(it);
        return func(s, st, 0);
    }
=======
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[301];
    bool func(string &s, set<string> &st, int i){
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j=i; j<s.size(); j++){
            temp+=s[j];
            if(st.find(temp) != st.end()){
                if(func(s, st, j+1)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp, -1, sizeof dp);
        for(auto it:wordDict) st.insert(it);
        return func(s, st, 0);
    }
>>>>>>> 03827a8a737e6cdc0e00f9d1e79280e4808df36e
};