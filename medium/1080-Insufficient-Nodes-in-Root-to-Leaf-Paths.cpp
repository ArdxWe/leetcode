/*
 * Given the root of a binary tree and an integer limit, delete all insufficient
 * nodes in the tree simultaneously, and return the root of the resulting binary
 * tree. A node is insufficient if every root to leaf path intersecting this
 * node has a sum strictly less than limit. A leaf is a node with no children.
 */

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *sufficientSubset(TreeNode *root, int limit) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->left == nullptr && root->right == nullptr) {
      if (root->val < limit) {
        return nullptr;
      } else {
        return root;
      }
    }
    root->left = sufficientSubset(root->left, limit - root->val);
    root->right = sufficientSubset(root->right, limit - root->val);
    if (root->left == nullptr && root->right == nullptr) {
      return nullptr;
    }
    return root;
  }
};
