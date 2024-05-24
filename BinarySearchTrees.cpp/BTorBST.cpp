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
    bool func(TreeNode *node, long maxi, long mini){
        if(node==NULL) return true;
        if(node->val <= mini || node->val >= maxi) return false;
        bool left = func(node->left, node->val, mini);
        bool right = func(node->right, maxi, node->val);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        long maxi = LONG_MAX;
        long mini = LONG_MIN;
        return func(root, maxi, mini);
    }
};