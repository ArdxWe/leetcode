/* Given the head of a linked list, return the list after sorting it in
 * ascending order.
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
  ListNode* sortList(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* mid = medium(head);
    ListNode* next = mid->next;

    // only one
    if (next == nullptr) {
      return mid;
    }

    // split
    mid->next = nullptr;

    // merge
    return merge(sortList(head), sortList(next));
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

  ListNode* merge(ListNode* a, ListNode* b) {
    if (a == nullptr) {
      return b;
    } else if (b == nullptr) {
      return a;
    }

    ListNode* res = nullptr;
    ListNode* eve = nullptr;

    ListNode* a_now = a;
    ListNode* b_now = b;
    int now = 0;

    while (a_now != nullptr || b_now != nullptr) {
      if (a_now == nullptr) {
        eve->next = b_now;
        return res;
      } else if (b_now == nullptr) {
        eve->next = a_now;
        return res;
      }

      if (a_now->val < b_now->val) {
        if (eve == nullptr) {
          eve = a_now;
          res = a_now;

          a_now = a_now->next;
        } else {
          eve->next = a_now;
          eve = eve->next;
          a_now = a_now->next;
        }
      } else {
        if (eve == nullptr) {
          eve = b_now;
          res = b_now;

          b_now = b_now->next;
        } else {
          eve->next = b_now;
          eve = eve->next;
          b_now = b_now->next;
        }
      }
    }
    return res;
  }
};
