#include<bits/stdc++.h>
using namespace std;

//adjacency list from vertex source to dest
void AddEdge(vector<int> adj[], int source, int dest){
    adj[source].push_back(dest);
}

//printing adjacency list
void DisplayGraph(vector<int> adj[], int v){
    for(int i=0; i<v; i++){
        cout<< i<< "--> ";
        for(int j=0; j<adj[i].size(); j++){
            cout<< adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

//transpose of a graph
void TransposeGraph(vector<int> adj[], vector<int> transpose[], int v){
    for(int i=0; i<v; i++){
        for(int j=0; j<adj[i].size(); j++){
            AddEdge(transpose, adj[i][j], i);
        }
    }
}

int main()
{
    int v = 5;
    vector<int> adj[v];
    AddEdge(adj, 0, 1);
    AddEdge(adj, 0, 4);
    AddEdge(adj, 0, 3);
    AddEdge(adj, 2, 0);
    AddEdge(adj, 3, 2);
    AddEdge(adj, 4, 1);
    AddEdge(adj, 4, 3);

    DisplayGraph(adj,v);
 
    // Finding transpose of graph represented
    // by adjacency list adj[]
    vector<int> transpose[v];
    TransposeGraph(adj, transpose, v);
 
    // displaying adjacency list of transpose
    // graph i.e. b
    DisplayGraph(transpose, v);
 
    return 0;
}