#include<bits/stdc++.h>
using namespace std;

using namespace std;
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root==NULL) return s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node==NULL) s.append("#,");
            else s.append(to_string(node->val) + ',');
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str,',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            getline(s, str, ',');
            if(str=="#") node->left = NULL;
            else{
                TreeNode *nleft = new TreeNode(stoi(str));
                node->left = nleft;
                q.push(nleft);
            }
            getline(s, str, ',');
            if(str=="#") node->right = NULL;
            else{
                TreeNode *nright = new TreeNode(stoi(str));
                node->right = nright;
                q.push(nright);
            }
        }
        return root;
    }
};