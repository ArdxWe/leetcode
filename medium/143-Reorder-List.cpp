/* You are given the head of a singly linked-list. The list can be represented
 * as: L0 → L1 → … → Ln - 1 → Ln Reorder the list to be on the following form:
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * You may not modify the values in the list's nodes. Only nodes themselves may
 * be changed.
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
  void reorderList(ListNode* head) {
    ListNode* middle = medium(head);
    if (middle == nullptr) {
      return;
    }

    ListNode* last = middle->next;
    middle->next = nullptr;

    last = reverse(last);

    ListNode* now = head;

    ListNode* temp_head;
    ListNode* temp_last;

    // merge
    while (now != nullptr && last != nullptr) {
      temp_head = now->next;
      temp_last = last->next;

      now->next = last;
      last->next = temp_head;

      now = temp_head;
      last = temp_last;
    }
  }

  ListNode* medium(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next->next;

    while (fast != nullptr) {
      slow = slow->next;

      if (fast->next == nullptr) {
        return slow;
      } else {
        fast = fast->next->next;
      }
    }
    return slow;
  }

  ListNode* reverse(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* prev = nullptr;
    ListNode* now = head;
    ListNode* next;

    while (now != nullptr) {
      next = now->next;

      now->next = prev;

      prev = now;
      now = next;
    }
    return prev;
  }
};
