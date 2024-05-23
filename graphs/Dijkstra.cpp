#include<bits/stdc++.h>
using namespace std;

class DijkstraUsingPQ{
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        //implementing a priority queue in cpp
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i=0; i<V; i++) dist[i] = 1e9;
        
        dist[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int Node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto it: adj[Node]){
                int edgeWt = it[1];
                int adjNode = it[0];
                //relaxation of edge
                if(edgeWt + dist[Node] < dist[adjNode]){
                    dist[adjNode] = edgeWt + dist[Node];
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return dist;
    }
};


class DijkstraUsingSET{
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        set<pair<int,int>> st;
        vector<int> dist(V);
        for(int i=0; i<V; i++) dist[i] = 1e9;
        
        dist[S] = 0;
        st.insert({0,S});
        
        while(!st.empty()){
            auto it = *(st.begin());
            int Node = it.second;
            int d = it.first;
            st.erase(it);
            for(auto it: adj[Node]){
                int edgeWt = it[1];
                int adjNode = it[0];
                
                if(edgeWt + dist[Node] < dist[adjNode]){
                    if(dist[adjNode] != 1e9)
                        st.erase({edgeWt, adjNode});

                    dist[adjNode] = edgeWt + dist[Node];
                    st.insert({edgeWt, adjNode});
                }
            }
        }
        return dist;
    }
};

//print path of shortest path
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> parent(n+1), dist(n+1, 1e9);
        for(int i=1; i<n+1; i++){
            parent[i]= i;
        }
        dist[1] = 0;
        pq.push({0,1});
        
        while(!pq.empty()){
            int Node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            for(auto it : adj[Node]){
                int adjNode = it.first;
                int Wt = it.second;
                
                if(Wt + d < dist[adjNode]){
                    dist[adjNode] = d + Wt;
                    pq.push({d+Wt , adjNode});
                    parent[adjNode] = Node;
                }
            }
        }
        vector<int> path; int node = n;
        if(dist[n]== 1e9) return {-1};
        
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }