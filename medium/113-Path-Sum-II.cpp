/* Given the root of a binary tree and an integer targetSum, return all
 * root-to-leaf paths where the sum of the node values in the path equals
 * targetSum. Each path should be returned as a list of the node values, not
 * node references. A root-to-leaf path is a path starting from the root and
 * ending at any leaf node. A leaf is a node with no children.
 */

#include <vector>

using std::vector;

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
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    dfs(root, 0, targetSum);
    return res_;
  }

  void dfs(TreeNode *head, int val, int targetSum) {
    if (head == nullptr) {
      return;
    }

    val += head->val;
    now_.push_back(head->val);
    if (head->left == nullptr && head->left == head->right &&
        val == targetSum) {
      res_.push_back(now_);
    } else {
      dfs(head->left, val, targetSum);
      dfs(head->right, val, targetSum);
    }

    now_.pop_back();
  }

 private:
  vector<vector<int>> res_{};
  vector<int> now_{};
};
