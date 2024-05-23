#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *left;
        Node *right;
        int val;        
};
class sol{
    public:
    bool isLeaf(Node *node){
        if(!node->left && !node->right) return true;
        return false;
    }
    void addLeftBoundary(Node *node, vector<int> &ans){
        Node *curr = node->left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    void addLeaves(Node *node, vector<int> &ans){
        if(isLeaf(node)){
            ans.push_back(node->data);
            return ;
        }
        if(root->left) addLeaves(root->left, res);
        if(root->right) addLeaves(root->right, res);
    }
    void addRightBoundary(Node *node, vector<int> &ans){
        Node *curr = node->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }
    vector<int> BoundaryTraversal(Node *root){
        vector<int> ans;
        if(!root) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans); //but reversed
        return ans;
    }
};