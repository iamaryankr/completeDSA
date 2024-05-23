#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;
        vector<int> lcandy(n ,1);
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                lcandy[i] = lcandy[i-1]+1;
            }
        }
        vector<int> rcandy(n ,1);
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                rcandy[i] = rcandy[i+1]+1;
            }
        }
        for(int i=0; i<n; i++){
            ans += max(lcandy[i], rcandy[i]);
        }
        return ans;
    }
};