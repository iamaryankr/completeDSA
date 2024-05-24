#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        TreeNode *left, *right;
        int val;
        TreeNode(): val(0), left(NULL), right(NULL){};
        TreeNode(int x): val(x), left(NULL), right(NULL){};
};
class Solution {
public:
     TreeNode* fp(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            if(current->val==start) res=current;
            if(current->left){
                q.push(current->left);
                parent[current->left]=current;
            }
            if(current->right){
                q.push(current->right);
                parent[current->right]=current;
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* st;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
              if(node->left->val==start){
                  st=node->left;
                  break;}
              q.push(node->left);
            }
            if(node->right){
              if(node->right->val==start){
                  st=node->right;
                  break;}
              q.push(node->right);
            }
        }
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* st=fp(root,parent,start);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> qu;
        qu.push(st);
        vis[st]=true;
        int t=0;
        while(!qu.empty()){
            int f=0;
           int s=qu.size();
           for(int i=0;i<s;i++){
                TreeNode* curr=qu.front();
           qu.pop();
           if(curr->left && !vis[curr->left]){
               f=1;
               qu.push(curr->left);
               vis[curr->left]=true;
           }
           if(curr->right && !vis[curr->right]){
               f=1;
               qu.push(curr->right);
               vis[curr->right]=true;
           }
           if(parent[curr] && !vis[parent[curr]]){
               f=1;
               qu.push(parent[curr]);
               vis[parent[curr]]=true;
           }
           
        }
        if(f) t++;
    }
    return t;
    }
};