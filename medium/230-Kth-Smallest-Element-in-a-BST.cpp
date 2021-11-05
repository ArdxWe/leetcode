/* Given the root of a binary search tree, and an integer k, return the kth
 * smallest value (1-indexed) of all the values of the nodes in the tree.
 */

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

class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
    vector<int> v;
    return get_sorted(&v, root, k);
  }

 private:
  int get_sorted(vector<int> *v, TreeNode *node, int k) {
    if (v->size() >= k) {  // quick return
      return (*v)[k - 1];
    }
    if (node == nullptr) {
      return -1;
    }

    int _ = get_sorted(v, node->left, k);
    // maybe ok
    if (_ != -1) {
      return _;
    }

    v->push_back(node->val);
    return get_sorted(v, node->right, k);
  }
};
