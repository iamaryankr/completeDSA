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
    void func(TreeNode* root, vector<int> &ans, int lvl){
        if(root==NULL) return ;
        if(lvl == ans.size()) ans.push_back(root->val);
        func(root->right, ans, lvl+1);
        func(root->left, ans, lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        int lvl = 0;
        func(root, ans, lvl);
        return ans;
    }
};