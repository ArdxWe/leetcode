/*
 * In a linked list of size n, where n is even, the ith node (0-indexed) of the
 * linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2)
 * - 1. For example, if n = 4, then node 0 is the twin of node 3, and node 1 is
 * the twin of node 2. These are the only nodes with twins for n = 4. The twin
 * sum is defined as the sum of a node and its twin. Given the head of a linked
 * list with even length, return the maximum twin sum of the linked list.
 */

#include <vector>
//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  int pairSum(ListNode *head) {
    std::vector<int> v;
    while (head != nullptr) {
      v.push_back(head->val);
      head = head->next;
    }

    int size = v.size();
    int res = v[size / 2] + v[(size / 2) - 1];
    for (int i = size / 2; i < size; i++) {
      res = std::max(res, v[i] + v[size - 1 - i]);
    }
    return res;
  }
};
