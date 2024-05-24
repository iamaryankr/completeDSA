#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* func(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd, map<int,int> &mp){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* newroot = new TreeNode(preorder[preStart]);
        int element = mp[preorder[preStart]];
        int newelement = element - inStart;
        newroot->left = func(preorder, inorder, preStart+1,
        preStart+newelement, inStart, element-1, mp);
        newroot->right = func(preorder, inorder, preStart+newelement+1, 
        preEnd, element+1, inEnd, mp);
        return newroot;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(), m = inorder.size();
        int preStart = 0, preEnd = n-1;
        int inStart = 0, inEnd = m-1;
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return func(preorder, inorder, preStart, preEnd, inStart, inEnd, mp);
    }
};