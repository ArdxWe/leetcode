/*
 * Given two binary search trees root1 and root2, return a list containing all
 * the integers from both trees sorted in ascending order.
 */

#include <vector>

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

namespace {
using std::vector;

void traverse(TreeNode* head, vector<int>* out) {
  if (head == nullptr) {
    return;
  }

  traverse(head->left, out);
  out->push_back(head->val);
  traverse(head->right, out);
}

vector<int> merge(const vector<int>& v1, const vector<int>& v2) {
  vector<int> res(v1.size() + v2.size(), 0);

  int cursor1 = 0;
  int cursor2 = 0;

  int res_cursor = 0;

  for (int i = 0; i < v1.size() + v2.size(); i++) {
    if (cursor1 >= v1.size()) {
      for (int j = res_cursor; j < v1.size() + v2.size(); j++) {
        res[j] = v2[cursor2++];
      }
      break;
    } else if (cursor2 >= v2.size()) {
      for (int j = res_cursor; j < v1.size() + v2.size(); j++) {
        res[j] = v1[cursor1++];
      }
      break;
    }

    if (v1[cursor1] > v2[cursor2]) {
      res[res_cursor++] = v2[cursor2++];
    } else {
      res[res_cursor++] = v1[cursor1++];
    }
  }

  return res;
}
}  // namespace

class Solution {
 public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> v1;
    traverse(root1, &v1);

    vector<int> v2;
    traverse(root2, &v2);

    return merge(v1, v2);
  }
};
