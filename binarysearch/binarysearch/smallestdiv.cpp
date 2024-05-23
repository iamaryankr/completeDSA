#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumofDiv(vector<int> &nums, int val){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += ceil((double)nums[i]/(double)val);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 1, high = nums[n-1];
        int ans = -1;
        
        while(low<=high){
            int mid = high + (low-high)/2;
            if(sumofDiv(nums, mid) <= threshold){
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