/* Given an integer n, return all the structurally unique BST's (binary search
 * trees), which has exactly n nodes of unique values from 1 to n. Return the
 * answer in any order.
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
  vector<TreeNode *> generateTrees(int n) { return f(1, n); }

  vector<TreeNode *> f(int start, int end) {
    if (start > end) {
      vector<TreeNode *> res;
      res.push_back(nullptr);
      return res;
    }

    vector<TreeNode *> res;
    for (int i = start; i <= end; i++) {
      vector<TreeNode *> left = f(start, i - 1);
      vector<TreeNode *> right = f(i + 1, end);

      for (int j = 0; j < left.size(); j++) {
        for (int k = 0; k < right.size(); k++) {
          TreeNode *head = new TreeNode(i, nullptr, nullptr);
          head->left = left[j];
          head->right = right[k];
          res.push_back(head);
        }
      }
    }

    return res;
  }
};