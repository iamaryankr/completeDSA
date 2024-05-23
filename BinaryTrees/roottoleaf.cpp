#include<bits/stdc++.h>
using namespace std;
void getPaths(BinaryTreeNode<int>* node, 
vector<int> &ans, vector<string> &res){
    if(!node) return;
    ans.push_back(node->data);
    if(node->left) getPaths(node->left, ans, res);
    if(node->right) getPaths(node->right, ans, res);
    if(node->left==NULL && node->right==NULL){
        string s=""
        for(auto x : ans){
            s+=to_string(x);
            s+=" ";
        }
        res.push_back(s);
    }
    ans.pop_back();
}
vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    vector<int> ans;
    vector<string> res;
    if(!root) return res;
    getPaths(root, ans, res);
    return res;

}