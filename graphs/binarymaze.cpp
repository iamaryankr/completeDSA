#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {0,0}});
        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        dist[0][0] = 0;

        //using 8 directions
        int delrow[] = {0,-1,-1,-1,0,1,1,1};
        int delcol[] = {-1,-1,0,1,1,1,0,-1};

        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dis = q.front().first;
            q.pop();
            for(int i=0; i<8; i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow<n && nrow>=0 && ncol<n && ncol>=0 && 
                grid[nrow][ncol]==0){
                    if(dis+1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = dis + 1;
                        q.push({dis+1, {nrow, ncol}});
                    }
                }
            }
        }
        if(dist[n-1][n-1]>=1e9) return -1;
        return dist[n-1][n-1]+1;
    }
};