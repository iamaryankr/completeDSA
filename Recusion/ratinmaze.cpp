<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

void rat(vector<vector<int>> &mat,int x,int y,
vector<string> &ans,string s){
    int rows = mat.size();
    int cols = mat[0].size();
    if(x==rows-1 && y==cols-1){
        ans.push_back(s);
        return ;
    }
    vector<int> r={-1,1,0,0};
    vector<int> c={0,0,-1,1};//up down l r
    vector<string>  ss={"U","D","L","R"};
    for(int i=0;i<4;i++){
        int row=x+r[i];
        int col=y+c[i];
        if(row>=0 && row<rows && col<cols && col>=0 && mat[row][col]==1){     
            mat[row][col]=0;
            rat(mat,row,col,ans,s+ss[i]);
            mat[row][col]=1;          
        }
    }
}
vector<string> ratMaze(vector<vector<int>> &mat) {
    vector<string> ans;
    string s="";
    mat[0][0]=0;
    rat(mat,0,0,ans,s);
    return ans;

=======
#include<bits/stdc++.h>
using namespace std;

void rat(vector<vector<int>> &mat,int x,int y,
vector<string> &ans,string s){
    int rows = mat.size();
    int cols = mat[0].size();
    if(x==rows-1 && y==cols-1){
        ans.push_back(s);
        return ;
    }
    vector<int> r={-1,1,0,0};
    vector<int> c={0,0,-1,1};//up down l r
    vector<string>  ss={"U","D","L","R"};
    for(int i=0;i<4;i++){
        int row=x+r[i];
        int col=y+c[i];
        if(row>=0 && row<rows && col<cols && col>=0 && mat[row][col]==1){     
            mat[row][col]=0;
            rat(mat,row,col,ans,s+ss[i]);
            mat[row][col]=1;          
        }
    }
}
vector<string> ratMaze(vector<vector<int>> &mat) {
    vector<string> ans;
    string s="";
    mat[0][0]=0;
    rat(mat,0,0,ans,s);
    return ans;

>>>>>>> 03827a8a737e6cdc0e00f9d1e79280e4808df36e
}