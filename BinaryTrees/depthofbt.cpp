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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int l= maxDepth(root->left);
        int r= maxDepth(root->right);
        if(l>r) return l+1;
        return r+1;
    }
};