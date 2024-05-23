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

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
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

    Graph obj;
    vector<int> ans = obj.BFSgraph(v,adj);
    printAns(ans);

 
    return 0;
}