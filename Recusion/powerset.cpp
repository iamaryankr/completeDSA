<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

//nums having unique elements only
class Solution {
public:
    vector<vector<int>> ans; vector<int>temp;
    void func(vector<int> &nums, int i, int n){
        if(i>n-1){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(nums, i+1, n);
        temp.pop_back();
        func(nums, i+1, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        func(nums, 0, n);
        return ans;
    }
};


//for nums having duplicates
class Solution {
public:
    set<vector<int>> ans; vector<int>temp;
    void func(vector<int> &nums, int i, int n){
        if(i>n-1){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(nums, i+1, n);
        temp.pop_back();
        func(nums, i+1, n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        func(nums, 0, n);
        vector<vector<int>> res;
        for(auto it: ans){
            res.push_back(it);
        }
        return res;
    }
=======
#include<bits/stdc++.h>
using namespace std;

//nums having unique elements only
class Solution {
public:
    vector<vector<int>> ans; vector<int>temp;
    void func(vector<int> &nums, int i, int n){
        if(i>n-1){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(nums, i+1, n);
        temp.pop_back();
        func(nums, i+1, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        func(nums, 0, n);
        return ans;
    }
};


//for nums having duplicates
class Solution {
public:
    set<vector<int>> ans; vector<int>temp;
    void func(vector<int> &nums, int i, int n){
        if(i>n-1){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(nums, i+1, n);
        temp.pop_back();
        func(nums, i+1, n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        func(nums, 0, n);
        vector<vector<int>> res;
        for(auto it: ans){
            res.push_back(it);
        }
        return res;
    }
>>>>>>> 03827a8a737e6cdc0e00f9d1e79280e4808df36e
};