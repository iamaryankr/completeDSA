#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(vector<int> &arr, int rate){
        int tot_hours = 0;
        for(int i=0; i<arr.size(); i++){
            tot_hours += ceil((double)arr[i]/(double)rate);
        }
        return tot_hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int low = 1; int high = piles[n-1];
        int ans = INT_MAX;
        
        while(low<=high){
            int mid = high + (low-high)/2;
            if(func(piles, mid)<=h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};