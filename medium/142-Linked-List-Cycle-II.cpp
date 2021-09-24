/* Given the head of a linked list, return the node where the cycle begins. If
 * there is no cycle, return null. There is a cycle in a linked list if there is
 * some node in the list that can be reached again by continuously following the
 * next pointer. Internally, pos is used to denote the index of the node that
 * tail's next pointer is connected to (0-indexed). It is -1 if there is no
 * cycle. Note that pos is not passed as a parameter. Do not modify the linked
 * list.
 */

#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> set;

    if (head == nullptr) {
      return nullptr;
    }

    set.insert(head);

    ListNode *prev = head;
    ListNode *now = head->next;
    while (now != nullptr) {
      if (set.find(now) != set.end()) {
        return now;
      } else {
        set.insert(now);
      }
      prev = now;
      now = now->next;
    }
    return nullptr;
  }
};
