/* Given the head of a sorted linked list, delete all nodes that have duplicate
 * numbers, leaving only distinct numbers from the original list. Return the
 * linked list sorted as well.
 */

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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = nullptr;

    ListNode* new_list = nullptr;
    ListNode* now = head;

    ListNode* temp;

    int prev_val = -101;

    while (now != nullptr) {
      // equals to next
      if (now->next != nullptr && now->val == now->next->val) {
        prev_val = now->val;
        now = now->next->next;
        continue;
      }

      // equals to prev
      if (now->val == prev_val) {
        now = now->next;
        continue;
      }

      temp = now->next;

      if (new_list == nullptr) {
        new_list = now;
        now->next = nullptr;
        res = now;
      } else {
        new_list->next = now;
        new_list = now;
        now->next = nullptr;
      }
      now = temp;
    }
    return res;
  }
};
