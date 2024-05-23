#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canWePlace(vector<int> &arr,int dist, int cows){
        int cntCows = 1;
        int last = arr[0];
        for(int i=1; i<arr.size(); i++){
            if(arr[i]-last >= dist){
                cntCows++;
                last = arr[i];
            }
            if(cntCows>= cows) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& arr, int cows){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int low = 0, high = arr[n-1]-arr[0];
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canWePlace(arr, mid, cows)==true){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};