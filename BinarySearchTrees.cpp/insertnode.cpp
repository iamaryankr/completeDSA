#include<bits/stdc++.h>
using namespace std;

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