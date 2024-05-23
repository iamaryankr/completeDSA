#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;
            long long first, last;
            for(int i=0; i<size; i++){
                int currid = q.front().second - mmin;
                TreeNode *node = q.front().first;
                q.pop();
                if(i==0) first = currid;
                if(i==size-1) last = currid;
                if(node->left) q.push({node->left, 2*currid+1});
                if(node->right) q.push({node->right, 2*currid+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};