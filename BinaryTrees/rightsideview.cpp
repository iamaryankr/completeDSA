#include<bits/stdc++.h>
using namespace std;

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