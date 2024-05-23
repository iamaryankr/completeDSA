#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func(string &num, int target, int ind, vector<string> &ans,
    string temp, long long prevNum, long long currSum, int n){
        if(ind==num.size() && currSum==target){
            ans.push_back(temp);
            return; 
        }
        for(int len=1; len<=(n-ind); len++){
            string number = num.substr(ind, len);
            if(number[0]=='0' && number.size()>1) continue;
            
            long long currNum = stoll(number);
            func(num, target, ind+len, ans, temp+"+"+number,
            currNum, currSum+currNum, n);
            func(num, target, ind+len, ans, temp+"-"+number,
            -currNum, currSum-currNum, n);
            func(num, target, ind+len, ans, temp+"*"+number,
            currNum*prevNum, currSum-prevNum+currNum*prevNum, n);
        }
    }
    vector<string> addOperators(string num, int target){
        vector<string> ans;
        int n = num.size();
        for(int l=1; l<=n; l++){
            string number = num.substr(0, l);
            if(number[0]=='0' && number.size()>1) continue;
            long long currNum = stoll(number);
            func(num, target, l, ans, number, currNum, currNum, n);
        }
        return ans;
    }
};