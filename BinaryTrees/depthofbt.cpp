#include<bits/stdc++.h>
using namespace std;

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