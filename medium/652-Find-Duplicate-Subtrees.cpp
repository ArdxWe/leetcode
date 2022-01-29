/* Given the root of a binary tree, return all duplicate subtrees.
 * For each kind of duplicate subtrees, you only need to return the root node of
 * any one of them. Two trees are duplicate if they have the same structure with
 * the same node values.
 */

#include <string>
#include <unordered_map>
#include <vector>

namespace {
using std::string;
using std::to_string;
using std::unordered_map;
using std::vector;
}  // namespace

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
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> res;
    dfs(root, &res);
    return res;
  }

 private:
  void dfs(TreeNode* node, vector<TreeNode*>* output) {
    if (node == nullptr) {
      return;
    }

    string ser = serializer(node);
    if (map_.find(ser) == map_.end()) {
      map_[ser] = false;
    } else {
      if (map_[ser] == false) {
        map_[ser] = true;
        output->push_back(node);
      }
    }

    dfs(node->left, output);
    dfs(node->right, output);
  }

  string serializer(TreeNode* root) {
    if (root == nullptr) {
      return "-";
    }

    if (cache_.find(root) != cache_.end()) {
      return cache_[root];
    }

    string res;
    res += to_string(root->val);

    res += ' ' + serializer(root->left);
    res += ' ' + serializer(root->right);
    cache_[root] = res;
    return res;
  }

  unordered_map<TreeNode*, string> cache_{};
  unordered_map<string, bool> map_{};
};
