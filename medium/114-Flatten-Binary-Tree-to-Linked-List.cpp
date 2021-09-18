/* Given the root of a binary tree, flatten the tree into a "linked list":
 * The "linked list" should use the same TreeNode class where the right child
 * pointer points to the next node in the list and the left child pointer is
 * always null. The "linked list" should be in the same order as a pre-order
 * traversal of the binary tree.
 */

#include <cassert>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  struct my_func {
    TreeNode* operator()(TreeNode* head) {
      TreeNode* now = head;
      assert(now != nullptr);
      while (now->right != nullptr) {
        now = now->right;
      }
      return now;
    }
  };

  void flatten(TreeNode* root) { dfs(root); }

  void dfs(TreeNode* head) {
    if (head == nullptr) {
      return;
    }
    dfs(head->right);
    dfs(head->left);

    if (head->left != nullptr) {
      TreeNode* temp = head->right;
      head->right = head->left;
      f_(head->left)->right = temp;
      head->left = nullptr;
    }
  }

 private:
  my_func f_;
};
