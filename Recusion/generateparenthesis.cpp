#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    void generate(int open, int close,string &s){
       if(open==0 && close==0){
           ans.push_back(s);
           return;
       }
       if(open>0){
           s.push_back('(');
           generate(open-1, close, s);
           s.pop_back();
       }
       if(close>0 && close>open){
           s.push_back(')');
           generate(open, close-1, s);
           s.pop_back();
       }
    }
    vector<string> generateParenthesis(int n) {
       string s = "";
       generate(n, n, s);
       return ans;
    }
};