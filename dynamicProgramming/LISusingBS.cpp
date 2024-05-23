#include<bits/stdc++.h>
using namespace std;

class sol{
public:
    //only gives the length
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i=0; i<n; i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(),
                nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};