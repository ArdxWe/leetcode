/*
 * Given two integer arrays, preorder and postorder where preorder is the
 * preorder traversal of a binary tree of distinct values and postorder is the
 * postorder traversal of the same tree, reconstruct and return the binary tree.
 * If there exist multiple answers, you can return any of them.
 */

#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

bool same(vector<int>& a, vector<int>& b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

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
  TreeNode* constructFromPrePost(vector<int>& preorder,
                                 vector<int>& postorder) {
    return construct(preorder, 0, preorder.size() - 1, postorder, 0,
                     postorder.size() - 1);
  }

 private:
  TreeNode* construct(const vector<int>& pre, int a, int b,
                      const vector<int>& post, int c, int d) {
    if (a > b || c > d) {
      return nullptr;
    }
    TreeNode* res = new TreeNode(pre[a]);
    if (a == b && c == d) {
      return res;
    }

    auto lambda = [](const vector<int>& v, int a, int b) {
      vector<int> res;
      for (int i = a; i <= b; i++) {
        res.push_back(v[i]);
      }
      return res;
    };

    int start = a + 1;
    for (int i = start; i <= b; i++) {
      auto first = lambda(pre, start, i);
      auto second = lambda(post, c, c + i - start);
      if (same(first, second)) {
        res->left = construct(pre, start, i, post, c, c + i - start);
        res->right = construct(pre, i + 1, b, post, c + i - start + 1, d - 1);
        return res;
      }
    }
    return nullptr;
  }
};
