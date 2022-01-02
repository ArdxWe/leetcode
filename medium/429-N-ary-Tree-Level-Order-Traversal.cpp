/*
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value (See examples).
 */

#include <cassert>
#include <vector>

namespace {
using std::vector;
}  // namespace

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;

    if (root == nullptr) {
      return res;
    }

    vector<Node*> queue(1, root);

    auto write_to_res = [&res](const vector<Node*>& v) {
      vector<int> t;
      for (auto* p : v) {
        t.push_back(p->val);
      }

      res.push_back(move(t));
    };

    while (!queue.empty()) {
      write_to_res(queue);

      vector<Node*> new_queue;
      for (auto* t : queue) {
        assert(t != nullptr);

        if (t->children.empty()) {
          continue;
        }

        for (auto* x : t->children) {
          assert(x != nullptr);
          new_queue.push_back(x);
        }
      }

      queue = move(new_queue);
    }

    return res;
  }
};
