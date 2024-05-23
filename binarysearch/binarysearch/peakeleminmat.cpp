#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxElem(vector<vector<int>> &mat, int m,int n, int col){
        int maxVal = -1, index = -1;
        for(int i=0; i<m; i++){
            if(mat[i][col]>maxVal){
                maxVal = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = n-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            int row = maxElem(mat, m, n, mid);
            int left = mid-1>=0 ? mat[row][mid-1]:-1;
            int right = mid+1<n ? mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right) return {row, mid};
            else if(mat[row][mid]<left) high = mid-1;
            else low = mid+1;
        }
        return {-1,-1};
    }
};