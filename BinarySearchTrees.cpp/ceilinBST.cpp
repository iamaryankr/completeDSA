#include<bits/stdc++.h>
using namespace std;

int findCeil(BinaryTreeNode<int> *root, int key){
    // Write your code here.
    int ceil = -1;
    while(root){
        if(key < root->data){
            ceil = root->data;
            root = root->left;
        }
        else if(key > root->data){
            root = root->right;
        }
        else{
            ceil = key;
            break;
        }
    }
    return ceil;
}