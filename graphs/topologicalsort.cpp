#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void dfs(int node, vector<int> adj[], vector<int> &vis, stack <int> &stk ){
	    vis[node] = 1;
	    for(auto x: adj[node]){
	        if(!vis[x]){
	            dfs(x, adj, vis, stk);
	           
	        } 
	    }
	    stk.push(node); 
	}
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> vis(v,0);
	    stack <int> stk; 
	    vector<int> ans;
	    for(int i=0; i<v; i++){
	        if(!vis[i]){
	            dfs(i, adj, vis, stk);
	        }
	    }
	    while(!stk.empty()){
	        int a = stk.top();
	        ans.push_back(a);
	        stk.pop();
	    }
	    return ans;
	}

    //topo sort using bfs(KAHN's ALGORITHM)
    vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(v,0);
	    for(int i=0; i<v; i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0 ;i<v; i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    return topo;
	}
};