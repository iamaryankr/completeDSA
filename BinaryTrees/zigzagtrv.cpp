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
    void func(TreeNode* node, int level, vector<vector<int>>& ans){
        if(node==NULL) return ;
        if(level==ans.size()) ans.push_back({});
        ans[level].push_back(node->val);
        func(node->left, level+1, ans);
        func(node->right, level+1, ans);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        func(root, 0, ans);
        for(int i=1; i<ans.size(); i+=2){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};