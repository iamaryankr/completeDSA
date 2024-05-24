#include<bits/stdc++.h>
using namespace std;
class BinaryTreeNode{
    public:
        BinaryTreeNode *left, *right;
        int val;
        BinaryTreeNode(): val(0), left(NULL), right(NULL){};
        BinaryTreeNode(int x): val(x), left(NULL), right(NULL){};
};
int findCeil(BinaryTreeNode *root, int key){
    // Write your code here.
    int ceil = -1;
    while(root){
        if(key < root->val){
            ceil = root->val;
            root = root->left;
        }
        else if(key > root->val){
            root = root->right;
        }
        else{
            ceil = key;
            break;
        }
    }
    return ceil;
}