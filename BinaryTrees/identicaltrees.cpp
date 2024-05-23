#include<bits/stdc++.h>
using namespace std;

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