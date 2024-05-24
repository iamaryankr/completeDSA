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
    int heightHelper(TreeNode* node){
        if(node==NULL)return 0;
        int left = heightHelper(node->left);
        int right = heightHelper(node->right);
        if(left == -1 || right == -1)  return -1;
        if(abs(left-right) > 1)  return -1;
        return max(left, right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)   return true;
        if(heightHelper(root)==-1)  return false;
        return true;
    }
};