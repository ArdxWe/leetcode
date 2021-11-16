/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
 * in the tree. According to the definition of LCA on Wikipedia: “The lowest
 * common ancestor is defined between two nodes p and q as the lowest node in T
 * that has both p and q as descendants (where we allow a node to be a
 * descendant of itself).”
 */

#include <algorithm>
#include <vector>

namespace {
using std::min;
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

}  // namespace

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    p_ = p;
    q_ = q;

    {
      vector<TreeNode*> _;
      find(root, &_);
    }
    int size = min(p_path_.size(), q_path_.size());

    for (int i = size - 1; i >= 0; i--) {
      if (q_path_[i] == p_path_[i]) {
        return q_path_[i];
      }
    }
    return nullptr;
  }

  void find(TreeNode* root, vector<TreeNode*>* output) {
    if (root == nullptr) {
      return;
    }

    if (!p_path_.empty() && !q_path_.empty()) return;

    output->push_back(root);

    if (p_path_.empty() && root->val == p_->val) {
      p_path_ = *output;
    } else if (q_path_.empty() && root->val == q_->val) {
      q_path_ = *output;
    }

    find(root->left, output);
    find(root->right, output);
    output->pop_back();
  }

 private:
  TreeNode* p_ = nullptr;
  TreeNode* q_ = nullptr;
  vector<TreeNode*> p_path_{};
  vector<TreeNode*> q_path_{};
};
