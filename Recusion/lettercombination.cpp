<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    void func(string &digits, int i, map<int, string> &mpp, string &temp){ 
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        string a = mpp[digits[i]-'0'];
        for(int j=0; j<a.size(); j++){
            temp.push_back(a[j]);
            func(digits, i+1, mpp, temp);
            temp.pop_back(); 
        }  
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        map<int, string> mpp;
        mpp[2] = "abc"; mpp[3] = "def"; mpp[4] = "ghi"; mpp[5] = "jkl";
        mpp[6] = "mno"; mpp[7] = "pqrs"; mpp[8] = "tuv"; mpp[9] = "wxyz";
        
        string temp;
        func(digits, 0, mpp, temp);
        return ans;
    }   
=======
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    void func(string &digits, int i, map<int, string> &mpp, string &temp){ 
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        string a = mpp[digits[i]-'0'];
        for(int j=0; j<a.size(); j++){
            temp.push_back(a[j]);
            func(digits, i+1, mpp, temp);
            temp.pop_back(); 
        }  
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        map<int, string> mpp;
        mpp[2] = "abc"; mpp[3] = "def"; mpp[4] = "ghi"; mpp[5] = "jkl";
        mpp[6] = "mno"; mpp[7] = "pqrs"; mpp[8] = "tuv"; mpp[9] = "wxyz";
        
        string temp;
        func(digits, 0, mpp, temp);
        return ans;
    }   
>>>>>>> 03827a8a737e6cdc0e00f9d1e79280e4808df36e
};