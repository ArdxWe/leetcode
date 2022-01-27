/*
 * Given the root of a binary tree, the value of a target node target, and an
 * integer k, return an array of the values of all nodes that have a distance k
 * from the target node. You can return the answer in any order.
 */

#include <cassert>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    build_map(nullptr, root);
    compute(nullptr, target, k, 0);
    return res_;
  }

 private:
  void build_map(TreeNode* parent, TreeNode* head) {
    if (head == nullptr) {
      return;
    }
    map_[head] = parent;
    build_map(head, head->left);
    build_map(head, head->right);
  }

  void compute(TreeNode* prev, TreeNode* head, int k, int now) {
    if (head == nullptr) {
      return;
    }
    if (k == now) {
      res_.push_back(head->val);
      return;
    }
    assert(k > now);
    if (head->left != prev) {
      compute(head, head->left, k, now + 1);
    }
    if (head->right != prev) {
      compute(head, head->right, k, now + 1);
    }
    assert(map_.find(head) != map_.end());
    if (map_[head] != prev) {
      compute(head, map_[head], k, now + 1);
    }
  }

  unordered_map<TreeNode*, TreeNode*> map_{};
  vector<int> res_{};
};
