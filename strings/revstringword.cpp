#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //using stringstream 
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans;
        while(ss >> word){
            ans = word + " " + ans;
        }
        return ans.substr(0, ans.size()-1);
    }
    //without stringstream
    string reverseWords2(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int start = 0, end = 0;
        int i=0; 
        while(i<n){
            while(s[i]!= ' ' && i<n){
                s[end++] = s[i++];
            }
            if(start < end){
                reverse(s.begin()+ start , s.begin()+end);
                if(end==n) break;
                s[end++] = ' ';
                start = end;
            }
            i++;
        }
        if(end>0 && s[end-1]==' '){
            s.resize(end-1);
        }
        else{
            s.resize(end);
        }
        return s; 
    }
};