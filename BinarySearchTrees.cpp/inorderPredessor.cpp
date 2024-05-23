#include<bits/stdc++.h>
class TreeNode{
    public:
        int val;
        TreeNode* right, left;
        TreeNode(int x){
            left->NULL;
            right->NULL;
            data->x;
        }
};
pair<int, int> predecessorSuccessor(TreeNode *root, int key){
    int pred = -1;
    int succ = -1;
    TreeNode* temp = root;
    while(temp && temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    if(temp){
        // predecessor
        TreeNode* leftTree = temp->left;
        while(leftTree){
            pred = leftTree->data;
            leftTree = leftTree->right;
        }

        // successor
        TreeNode* rightTree = temp->right;
        while(rightTree){
            succ = rightTree->data;
            rightTree = rightTree->left;
        }
    }

    return {pred, succ};
}