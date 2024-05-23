#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
            vis[node] = 1;
            ls.push_back(node);

            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(it, adj, vis, ls);
                }
            }
        }
    public:
        vector<int> DFSgraph(int v, vector<int> adj[]){
            int vis[v] = {0};
            int start = 0;
            vector<int> ls;
            dfs(start, adj, vis, ls);
            return ls;
        }
        vector<int> BFSgraph(int v, vector<int> adj[]){
            vector<int> bfs;
            int visited[v] = {0};
            visited[0] = 1;

            queue<int> q;
            q.push(0);
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it: adj[node]){
                    if(!visited[it]){
                        visited[it] = 1;
                        q.push(it);
                    }
                }
            }
            return bfs;
        }
};