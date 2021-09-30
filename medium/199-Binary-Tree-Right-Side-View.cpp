/* Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to bottom.
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
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr) {
      return vector<int>{};
    }
    vector<int> res;
    TreeNode *node = root;

    vector<TreeNode *> level;
    level.push_back(node);

    vector<TreeNode *> temp;

    while (!level.empty()) {
      for (int i = 0; i < level.size(); i++) {
        if (level[i]->left) {
          temp.push_back(level[i]->left);
        }
        if (level[i]->right) {
          temp.push_back(level[i]->right);
        }
      }
      res.push_back(level[level.size() - 1]->val);

      level = temp;
      temp.clear();
    }
    return res;
  }
};
