#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  //shortest path using toposort as it is directed graph
    void toposort(int node, vector<int> &vis, vector<pair<int,int>> adj[],
    stack<int> &stk){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it.first]) toposort(it.first, vis, adj, stk);
        }
        stk.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(auto it: edges){
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
        }
        vector<int> vis(N, 0);
        stack<int> stk;
        for(int i=0; i<N; i++){
            if(!vis[i]) toposort(i, vis, adj, stk);
        }
        
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while(!stk.empty()){
            int node = stk.top();
            stk.pop();
            for(auto it: adj[node]){
                int u = it.first, wt = it.second;
                if(dist[node]+wt < dist[u]){
                    dist[u] = dist[node]+wt;
                }
            }
        }
        for(int i=0; i<N; i++){
            if(dist[i]==1e9) dist[i] = -1;
        }
        return dist;
    }
};