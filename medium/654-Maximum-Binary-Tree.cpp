/*
 * You are given an integer array nums with no duplicates. A maximum binary tree
 * can be built recursively from nums using the following algorithm: Create a
 * root node whose value is the maximum value in nums. Recursively build the
 * left subtree on the subarray prefix to the left of the maximum value.
 * Recursively build the right subtree on the subarray suffix to the right of
 * the maximum value. Return the maximum binary tree built from nums.
 */

#include <cassert>
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

int find_max_index(const vector<int> &v, int start, int end) {
  assert(start <= end);
  if (start == end) {
    return start;
  }
  int res = start;
  for (int i = start + 1; i <= end; i++) {
    if (v[res] < v[i]) {
      res = i;
    }
  }
  return res;
}

class Solution {
 public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return f(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode *f(const vector<int> &v, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    int max_index = find_max_index(v, start, end);
    TreeNode *res = new TreeNode(v[max_index]);
    res->left = f(v, start, max_index - 1);
    res->right = f(v, max_index + 1, end);
    return res;
  }
};
