#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        TreeNode *left, *right;
        int val;
        TreeNode(): val(0), left(NULL), right(NULL){};
        TreeNode(int x): val(x), left(NULL), right(NULL){};
};
//using recursion
class Solution {
public:
    void func(TreeNode* node, int level, vector<vector<int>>& ans){
        if(node==NULL) return ;
        if(level==ans.size()) ans.push_back({});
        ans[level].push_back(node->val);
        func(node->left, level+1, ans);
        func(node->right, level+1, ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        func(root, 0, ans);
        return ans;
    }
};
//using queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> temp;
            for(int i=0; i<s; i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left !=NULL) q.push(node->left);
                if(node->right !=NULL) q.push(node->right);
                temp.push_back(node->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};