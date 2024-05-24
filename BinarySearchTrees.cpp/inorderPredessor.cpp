#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        TreeNode *left, *right;
        int val;
        TreeNode(): val(0), left(NULL), right(NULL){};
        TreeNode(int x): val(x), left(NULL), right(NULL){};
};
pair<int, int> predecessorSuccessor(TreeNode *root, int key){
    int pred = -1;
    int succ = -1;
    TreeNode* temp = root;
    while(temp && temp->val != key){
        if(temp->val > key){
            succ = temp->val;
            temp = temp->left;
        }
        else{
            pred = temp->val;
            temp = temp->right;
        }
    }

    if(temp){
        // predecessor
        TreeNode* leftTree = temp->left;
        while(leftTree){
            pred = leftTree->val;
            leftTree = leftTree->right;
        }

        // successor
        TreeNode* rightTree = temp->right;
        while(rightTree){
            succ = rightTree->val;
            rightTree = rightTree->left;
        }
    }

    return {pred, succ};
}