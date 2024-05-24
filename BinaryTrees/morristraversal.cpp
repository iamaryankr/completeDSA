#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        TreeNode *left, *right;
        int val;
        TreeNode(): val(0), left(NULL), right(NULL){};
        TreeNode(int x): val(x), left(NULL), right(NULL){};
};

vector<int> preorderTraversal(TreeNode * root) {
  vector<int> preorder;

  TreeNode * cur = root;
  while (cur != NULL) {
    if (cur -> left == NULL) {
      preorder.push_back(cur -> val);
      cur = cur -> right;
    } else {
      TreeNode * prev = cur -> left;
      while (prev -> right != NULL && prev -> right != cur) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = cur;
        preorder.push_back(cur -> val);
        cur = cur -> left;
      } else {
        prev -> right = NULL;
        cur = cur -> right;
      }
    }
  }
  return preorder;
}

struct TreeNode * newNode(int val) {
  struct TreeNode * TreeNode = (struct TreeNode * ) malloc(sizeof(struct TreeNode));
  TreeNode -> val = val;
  TreeNode -> left = NULL;
  TreeNode -> right = NULL;

  return (TreeNode);
}