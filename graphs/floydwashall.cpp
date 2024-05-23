#include<bits/stdc++.h>
using namespace std;

class FloydWarshall{
    public:
        //multisource shortest path
    void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==-1) matrix[i][j] = 1e9;
	            if(i==j) matrix[i][i] = 0;
	        }
	    }    
	    for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j]= min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }   
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==1e9) matrix[i][j] = -1;
	        }
	    }    
	}
};
//find smallest city problemj
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        for(auto it: edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        int cntCity = n;
        int cityNo = -1;
        for(int city= 0; city<n; city++){
            int cnt = 0;
            for(int adjCity=0; adjCity<n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold) cnt++; 
            }
            if(cnt <= cntCity){
                cntCity = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }