#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        TreeNode *left, *right;
        int val;
        TreeNode(): val(0), left(NULL), right(NULL){};
        TreeNode(int x): val(x), left(NULL), right(NULL){};
};

bool isParentSum(TreeNode *root){
    int child = 0;
    if(root==NULL) return true;
    if(root->left) child += root->left->val;
    if(root->right) child += root->right->val;
    if(child != root->val && child!=0) return false;
    bool left = isParentSum(root->left);
    bool right = isParentSum(root->right);
    return left&&right;
}