#include<bits/stdc++.h>
using namespace std;
//detecting undirected graph cycle
class Soln{
public:
    bool detect(int src, vector<int> adj[], int vis[]){
      vis[src] = 1; 
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          for(auto adjacentNode: adj[node]) {
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              else if(parent != adjacentNode) {
                  return true; 
              }
          }
      }
      return false; 
  }

    bool isCyclebfs(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
        
    }
//detecting using dfs
    bool dfs(int node, int parent, int vis[], vector<int> adj[]){
        vis[node]= 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, node, vis, adj)==true) return true;
            }
            else if(it != parent) return true;
        }
        return false;
    }
    bool iscycledfs(int v, vector<int> adj[]){
        int vis[v] = {0};
        for(int i=0 ;i<v; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj)==true) return true;
            }
        }
        return false;
    }
    
};


//detecting directed graph cycle
class Sol{
public:
     bool dfs(vector<int> adj[], vector<int> vis, vector<int> pathvis, int node){
        pathvis[node] = 1;
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]) {
                if (dfs(adj, vis, pathvis, it)==true) return true;
            }
            else if(pathvis[it]==1) return true;
        }
        pathvis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        
        for(int i=0; i<V ;i++){
            if(!vis[i]){
                if(dfs(adj, vis, pathvis, i)==true) return true;
            }
        }
        return false;
    }
    
    //using bfs(KHAN's ALGO)
    //if(topo.size()== n) then there is no cycle else there exists a cycle
};
