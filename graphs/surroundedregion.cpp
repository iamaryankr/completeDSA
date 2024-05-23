#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, 
    vector<vector<char>> &board){
        int m = board.size(), n = board[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow<m && nrow>=0 && ncol<n && ncol>=0 &&
            !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow, ncol, vis, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for(int i=0; i<m; i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i, 0, vis, board);
            }
            if(board[i][n-1]=='O' && !vis[i][n-1]){
                dfs(i, n-1, vis, board);
            }
        }
        for(int j=0; j<n; j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0, j, vis, board);
            }
            if(board[m-1][j]=='O' && !vis[m-1][j]){
                dfs(m-1, j, vis, board);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};