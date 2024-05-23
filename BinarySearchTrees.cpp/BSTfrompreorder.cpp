#include<bits/stdc++.h>
class Solution {
public:
    TreeNode* func(vector<int>& preorder, int& i, int u_bound){
        if(i==preorder.size() || preorder[i] > u_bound) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = func(preorder, i, root->val);
        root->right = func(preorder, i, u_bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       int i = 0;
       int u_bound = INT_MAX;
       return func(preorder, i, u_bound);
    }