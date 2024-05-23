<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;


//my solution which did not work
class Solution {
public:
    bool func(vector<vector<char>> &board, string &word, int row, int col,
    int ind){
        int n = board.size(), m = board[0].size();
        bool found;
        if(ind==word.size()-1){
            return true;
        }
        if (row < 0 || row >= n || col < 0 || col >= m || 
        board[row][col] != word[ind]) {
            return false;
        }
        int delrow[] ={0,1,0-1};
        int delcol[] ={-1,0,1,0};
        for(int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if(board[nrow][ncol]==word[ind+1] && nrow<n && nrow>=0 
            && ncol<m && ncol>=0){
                found = found || func(board, word, nrow, ncol, ind+1);
            }   
        }
        return found;
    }
    bool exist(vector<vector<char>>& board, string word){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(func(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
//correct version of my solution
class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 and row < n and col >= 0 and col < m;
    }
    
    bool findWord(int row, int col, int ind, vector<vector<char>> &grid, 
            vector<vector<bool>> &vis, string &word) {
        if (ind == word.size()) {
            return true;
        }
        int n = grid.size();
        int m = grid[0].size();
        if (!isValid(row, col, n, m) or word[ind] != grid[row][col]
        or vis[row][col])  return false;
        
        vis[row][col] = true;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + delrow[i];
            int nCol = col + delcol[i];
            
            bool isPossible = findWord(nRow, nCol, ind+1, grid, vis, word);  
            if (isPossible) return true;
        }
        
        return vis[row][col] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (findWord(i, j, 0, board, vis, word)) 
                    return true;
            }
        }
        
        return false;
    }
};

//correct solution method-II
class Solution {
public:
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int n) {
        if(n == word.size()) return true; 
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]) return false;
        
        board[i][j] = '0';
        
        bool status = DFS(board, word, i + 1, j, n + 1) ||  //down
                        DFS(board, word, i, j + 1, n + 1) ||  //right
                        DFS(board, word, i - 1, j, n + 1) ||  //up
                        DFS(board, word, i, j - 1, n + 1);  //left
        
        board[i][j] = word[n];
		
        return status;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        
        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[i].size(); j++) 
                if(board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;
        
        return false;
    }
=======
#include<bits/stdc++.h>
using namespace std;


//my solution which did not work
class Solution {
public:
    bool func(vector<vector<char>> &board, string &word, int row, int col,
    int ind){
        int n = board.size(), m = board[0].size();
        bool found;
        if(ind==word.size()-1){
            return true;
        }
        if (row < 0 || row >= n || col < 0 || col >= m || 
        board[row][col] != word[ind]) {
            return false;
        }
        int delrow[] ={0,1,0-1};
        int delcol[] ={-1,0,1,0};
        for(int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if(board[nrow][ncol]==word[ind+1] && nrow<n && nrow>=0 
            && ncol<m && ncol>=0){
                found = found || func(board, word, nrow, ncol, ind+1);
            }   
        }
        return found;
    }
    bool exist(vector<vector<char>>& board, string word){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(func(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
//correct version of my solution
class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 and row < n and col >= 0 and col < m;
    }
    
    bool findWord(int row, int col, int ind, vector<vector<char>> &grid, 
            vector<vector<bool>> &vis, string &word) {
        if (ind == word.size()) {
            return true;
        }
        int n = grid.size();
        int m = grid[0].size();
        if (!isValid(row, col, n, m) or word[ind] != grid[row][col]
        or vis[row][col])  return false;
        
        vis[row][col] = true;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + delrow[i];
            int nCol = col + delcol[i];
            
            bool isPossible = findWord(nRow, nCol, ind+1, grid, vis, word);  
            if (isPossible) return true;
        }
        
        return vis[row][col] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (findWord(i, j, 0, board, vis, word)) 
                    return true;
            }
        }
        
        return false;
    }
};

//correct solution method-II
class Solution {
public:
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int n) {
        if(n == word.size()) return true; 
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]) return false;
        
        board[i][j] = '0';
        
        bool status = DFS(board, word, i + 1, j, n + 1) ||  //down
                        DFS(board, word, i, j + 1, n + 1) ||  //right
                        DFS(board, word, i - 1, j, n + 1) ||  //up
                        DFS(board, word, i, j - 1, n + 1);  //left
        
        board[i][j] = word[n];
		
        return status;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        
        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[i].size(); j++) 
                if(board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;
        
        return false;
    }
>>>>>>> 03827a8a737e6cdc0e00f9d1e79280e4808df36e
};