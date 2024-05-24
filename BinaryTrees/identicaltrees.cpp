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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==nullptr || q==nullptr) return false;
        if(p->val != q->val){
            return false;
        }
        bool rs = isSameTree(p->right, q->right);
        bool ls = isSameTree(p->left, q->left);
       

        return rs && ls;
    }
};