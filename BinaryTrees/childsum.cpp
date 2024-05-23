#include<bits/stdc++.h>
using namespace std;

bool isParentSum(Node *root){
    int child = 0;
    if(root==NULL) return true;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;
    if(child != root->data && child!=0) return false;
    bool left = isParentSum(root->left);
    bool right = isParentSum(root->right);
    return left&&right;
}