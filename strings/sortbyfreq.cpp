#include<bits/stdc++.h>
using namespace std;

//bucket sort
string frequencySort(string s) {
    unordered_map<char, int> mpp;
    for(int i=0; i<s.size(); i++){
        mpp[s[i]]++;
    }
    vector<string> bucket(s.size()+1, "");
    string ans;
    for(auto it: mpp){
        int n = it.second;
        char c = it.first;
        bucket[n].append(n, c);
    }
    for(int i=s.size(); i>0; i--){
        if(!bucket[i].empty()) ans+=bucket[i];
    }
    return ans;
}
//using heap
string frequencySort(string s) {
    unordered_map<char,int> freq;
    priority_queue<pair<int,char>> maxheap; 
    for(char c: s)
        freq[c]++;
    for(auto it: freq)
        maxheap.push({it.second,it.first}); 
    string a ="";   
    while(!maxheap.empty()){
        int n = maxheap.top().first;
        char c = maxheap.top().second;
        a+=string(n,c);
        maxheap.pop();
    }
    return a;
}
