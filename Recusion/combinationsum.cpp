<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

//combination sum-I
class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int> &candidates, int target, int i,
    vector<int> &arr){
        if(target==0){
            ans.push_back(arr);
            return;
        }
        if(i<candidates.size() && target>=candidates[i]){
            arr.push_back(candidates[i]);
            func(candidates, target-candidates[i], i, arr);
            arr.pop_back();
            
            func(candidates, target, i+1, arr);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        func(candidates, target, 0, arr);
        return ans;
    }
};


//combination sum-II
class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr,   
    vector<vector<int>> &ans, vector<int> &ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i+1, target - arr[i], arr, ans, ds);
            ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

//combination sum-III
class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int> &nums, int n, int i,int k, vector<int> &arr){
        if(n==0 && arr.size()==k){
            ans.push_back(arr);
            return;
        }
        if(i<nums.size() && n>=nums[i] && arr.size()<k){
            arr.push_back(nums[i]);
            func(nums, n-nums[i], i+1, k, arr);
            arr.pop_back();

            func(nums, n, i+1, k, arr);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> arr;
        func(nums, n, 0, k, arr);
        return ans;
    }
=======
#include<bits/stdc++.h>
using namespace std;

//combination sum-I
class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int> &candidates, int target, int i,
    vector<int> &arr){
        if(target==0){
            ans.push_back(arr);
            return;
        }
        if(i<candidates.size() && target>=candidates[i]){
            arr.push_back(candidates[i]);
            func(candidates, target-candidates[i], i, arr);
            arr.pop_back();
            
            func(candidates, target, i+1, arr);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        func(candidates, target, 0, arr);
        return ans;
    }
};


//combination sum-II
class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr,   
    vector<vector<int>> &ans, vector<int> &ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i+1, target - arr[i], arr, ans, ds);
            ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

//combination sum-III
class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int> &nums, int n, int i,int k, vector<int> &arr){
        if(n==0 && arr.size()==k){
            ans.push_back(arr);
            return;
        }
        if(i<nums.size() && n>=nums[i] && arr.size()<k){
            arr.push_back(nums[i]);
            func(nums, n-nums[i], i+1, k, arr);
            arr.pop_back();

            func(nums, n, i+1, k, arr);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> arr;
        func(nums, n, 0, k, arr);
        return ans;
    }
>>>>>>> 03827a8a737e6cdc0e00f9d1e79280e4808df36e
};