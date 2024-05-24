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
    TreeNode* insertIntoBST(TreeNode* node, int val) {
        if(node==NULL){
            node = new TreeNode(val);
            return node;
        }
        if(val < node->val){
            node->left = insertIntoBST(node->left, val);
        }
        else if(val > node->val){
            node->right = insertIntoBST(node->right, val);
        }
        return node;
    }
};