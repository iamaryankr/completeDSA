#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;  int h = m*n-1;
        while(l<=h){
            int mid = l+ (h-l)/2;
            int val = matrix[mid/n][mid%n];

            if(val==target) return true;
            else if(val<target) l = mid+1;
            else h = mid-1;
        }
        return false;  
    }
};