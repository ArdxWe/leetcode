/*
 * You are given the head of a linked list with n nodes.
 * For each node in the list, find the value of the next greater node. That is,
 * for each node, find the value of the first node that is next to it and has a
 * strictly larger value than it. Return an integer array answer where answer[i]
 * is the value of the next greater node of the ith node (1-indexed). If the ith
 * node does not have a next greater node, set answer[i] = 0.
 */

#include <vector>

namespace {
using std::vector;
}  // namespace

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  vector<int> nextLargerNodes(ListNode* head) {
    ListNode* cur = head;

    vector<ListNode*> v;
    while (cur != nullptr) {
      v.push_back(cur);
      cur = cur->next;
    }

    vector<int> stack;

    vector<int> res(v.size(), 0);

    for (int i = static_cast<int>(v.size() - 1); i >= 0; i--) {
      int now = v[i]->val;
      while (!stack.empty()) {
        int top = stack.back();

        if (top > now) {
          res[i] = top;
          break;
        } else {
          // remove smaller
          stack.pop_back();
        }
      }

      stack.push_back(now);
    }
    return res;
  }
};