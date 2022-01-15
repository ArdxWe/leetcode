/*
 * A complete binary tree is a binary tree in which every level, except possibly
 * the last, is completely filled, and all nodes are as far left as possible.
 * Design an algorithm to insert a new node to a complete binary tree keeping it
 * complete after the insertion. Implement the CBTInserter class:
 * CBTInserter(TreeNode root) Initializes the data structure with the root of
 * the complete binary tree. int insert(int v) Inserts a TreeNode into the tree
 * with value Node.val == val so that the tree remains complete, and returns the
 * value of the parent of the inserted TreeNode. TreeNode get_root() Returns the
 * root node of the tree.
 */

#include <cassert>
#include <vector>

namespace {
using std::vector;
}  // namespace

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

class CBTInserter {
 public:
  CBTInserter(TreeNode *root) {
    nodes_.clear();

    if (root == nullptr) {
      return;
    }

    vector<TreeNode *> queue;
    queue.push_back(root);

    while (!queue.empty()) {
      vector<TreeNode *> node;

      for (auto t : queue) {
        nodes_.push_back(t);
        if (t->left != nullptr) {
          node.push_back(t->left);
        }

        if (t->right != nullptr) {
          node.push_back(t->right);
        }
      }

      queue = node;
    }
  }

  int insert(int val) {
    TreeNode *node = new TreeNode{val};
    nodes_.push_back(node);

    assert(nodes_.size() >= 2);
    int prev_index = (nodes_.size() - 2) / 2;

    if (nodes_[prev_index]->left == nullptr) {
      nodes_[prev_index]->left = node;
    } else {
      nodes_[prev_index]->right = node;
    }

    return nodes_[(nodes_.size() - 2) / 2]->val;
  }

  TreeNode *get_root() {
    if (nodes_.empty()) {
      return nullptr;
    }

    return nodes_[0];
  }

 private:
  vector<TreeNode *> nodes_{};
};
