#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* func(TreeNode *node, TreeNode *p, TreeNode *q){
        if(node==NULL || node==p || node==q) return node;
        TreeNode *left = func(node->left, p, q);
        TreeNode *right = func(node->right, p, q);
        if(left==NULL) return right;
        if(right==NULL) return left;
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, 
    TreeNode* p, TreeNode* q){
        TreeNode * lca = func(root, p, q);
        return lca;
    }
};