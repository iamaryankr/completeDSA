#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return b[1]>a[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        int ans = -1;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> prev = intervals[0];
        for(auto it: intervals){
            if(prev[1] > it[0]) ans++;
            else prev = it;
        }
        return ans;
    }
};