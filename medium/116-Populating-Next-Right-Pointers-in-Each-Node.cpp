/* You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children. The binary tree has the following
 * definition: struct Node { int val; Node *left; Node *right; Node *next;
 * }
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL. Initially, all next
 * pointers are set to NULL.
 */

#include <vector>

using std::vector;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  explicit Node(int _val)
      : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr) {
      return nullptr;
    }

    Node* res = root;

    vector<Node*> v;
    v.push_back(root);

    vector<Node*> temp;

    while (!v.empty()) {
      for (int i = 0; i < v.size() - 1; i++) {
        v[i]->next = v[i + 1];
      }
      v[v.size() - 1]->next = nullptr;

      if (v[0]->left == nullptr) {
        break;
      }
      for (auto pointer : v) {
        temp.push_back(pointer->left);
        temp.push_back(pointer->right);
      }
      v = temp;
      temp.clear();
    }
    return res;
  }
};
