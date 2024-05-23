#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution{
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int count = 0;
        vector<int> ans;
        
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col]==1){
                ans.push_back(count);
                continue;
            }
            vis[row][col]=1;
            count++;
            
            int delrow[]= {-1,0,1,0};
            int delcol[]= {0,1,0,-1};
            for(int i=0; i<4; i++){
                int adjrow = row + delrow[i];
                int adjcol = col + delcol[i];
                if(adjcol>=0 && adjcol<m && adjrow>=0 && adjrow<n){
                    if(vis[adjrow][adjcol]==1){
                        int nodeNo = row*m + col;
                        int adjnodeNo = adjrow*m + adjcol;
                        if(ds.findUPar(nodeNo) != ds.findUPar(adjnodeNo)){
                            count--;
                            ds.unionByRank(nodeNo, adjnodeNo);
                        }
                    }
                }
            }
            ans.push_back(count);
            
        }
        return ans;
    }
};