#include<bits/stdc++.h>
using namespace std;

class Sol{
public:
        int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n]; int modulo = (int)(1e9+7);
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int,int>,
        vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;

        vector<int> dist(n, INT_MAX), ways(n,0);
        dist[0] = 0; ways[0] = 1;
        pq.push({0,0});  

        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dis+wt, adjNode});
                    ways[adjNode]= ways[node];
                }
                else if(dis + wt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%modulo;
                }
            }

        }
        return ways[n-1]%modulo;
    }
};