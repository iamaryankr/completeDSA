#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            unordered_map<char, int> mp;
            for(int j=i; j<n; j++){
                mp[s[j]]++;
                int minfreq = INT_MAX; int maxfreq = 0;
                for(auto it: mp){
                    maxfreq = max(maxfreq, it.second);
                    minfreq = min(minfreq, it.second);
                }
                sum = sum + (maxfreq-minfreq);
            }
        }
        return sum;
    }
};