#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int height(TreeNode *root, int &diameter){
        if(root==NULL) return 0;
        int l= height(root->left, diameter);
        int r= height(root->right, diameter);
        diameter = max(diameter, l+r);
        return max(l,r) +1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        int ht = height(root, dia);
        return dia;
    }
};