#include<bits/stdc++.h>
using namespace std;
//DSU and Kruskals algo
class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
            rank[i] = 0;
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

class KruskalAlgo{
    public:
        int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int, pair<int,int>>> edges;
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        int msWt = 0;
        for(auto it: edges){
            int u = it.second.first;
            int v = it.second.second;
            int wt = it.first;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionByRank(u,v);
                msWt += wt;
            }
        }
        return msWt;
    }
};