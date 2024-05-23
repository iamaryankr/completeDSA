<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool palindrome(string &s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            else{
                start++; end--;
            }
        }
        return true;
    }
    void solve(int ind,string &s, 
    vector<vector<string>>& ans,vector<string>& temp){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(palindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,ans,temp);
        return ans;
    }
=======
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool palindrome(string &s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            else{
                start++; end--;
            }
        }
        return true;
    }
    void solve(int ind,string &s, 
    vector<vector<string>>& ans,vector<string>& temp){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(palindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,ans,temp);
        return ans;
    }
>>>>>>> 03827a8a737e6cdc0e00f9d1e79280e4808df36e
};