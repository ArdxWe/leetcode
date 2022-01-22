/*
 * Given the root of a binary tree, the depth of each node is the shortest
 * distance to the root. Return the smallest subtree such that it contains all
 * the deepest nodes in the original tree. A node is called the deepest if it
 * has the largest depth possible among any node in the entire tree. The subtree
 * of a node is a tree consisting of that node, plus the set of all descendants
 * of that node.
 */

#include <unordered_map>

using std::unordered_map;

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
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    get_depths(root, 0);

    return minResult(root);
  }

 private:
  void get_depths(TreeNode *node, int now) {
    if (node == nullptr) {
      return;
    }
    max_ = std::max(max_, now);
    maps_[node] = now;
    get_depths(node->left, now + 1);
    get_depths(node->right, now + 1);
  }

  //
  TreeNode *minResult(TreeNode *node) {
    if (node == nullptr) {
      return nullptr;
    }
    if (maps_[node] == max_) {
      return node;
    }
    TreeNode *left = minResult(node->left);
    TreeNode *right = minResult(node->right);
    if (left != nullptr && right != nullptr) {
      return node;
    }
    if (left != nullptr) {
      return left;
    }
    if (right != nullptr) {
      return right;
    }
    return nullptr;
  }

  unordered_map<TreeNode *, int> maps_{};
  int max_ = 0;
};
