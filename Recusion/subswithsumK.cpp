<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
set<vector<int>> ans;
void func(vector<int> &arr, int sum, vector<int> &a, int i){
    if(sum==0){
        ans.insert(arr);
        return;
    }
    if(sum>=a[i]){
        arr.push_back(a[i]);
        func(arr, sum-a[i], a, i+1);
        arr.pop_back();
    }
    if(i<a.size()){
        func(arr, sum, a, i+1);
    }
}
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    // Write your code here
    vector<int> arr;
    vector<vector<int>> res;
    func(arr, k, a, 0);
    for (auto it: ans){
        res.push_back(it);
    }
    return res;
=======
#include<bits/stdc++.h>
using namespace std;
set<vector<int>> ans;
void func(vector<int> &arr, int sum, vector<int> &a, int i){
    if(sum==0){
        ans.insert(arr);
        return;
    }
    if(sum>=a[i]){
        arr.push_back(a[i]);
        func(arr, sum-a[i], a, i+1);
        arr.pop_back();
    }
    if(i<a.size()){
        func(arr, sum, a, i+1);
    }
}
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    // Write your code here
    vector<int> arr;
    vector<vector<int>> res;
    func(arr, k, a, 0);
    for (auto it: ans){
        res.push_back(it);
    }
    return res;
>>>>>>> 03827a8a737e6cdc0e00f9d1e79280e4808df36e
}