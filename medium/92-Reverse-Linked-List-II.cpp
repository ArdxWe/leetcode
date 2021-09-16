/* Given the head of a singly linked list and two integers left and right where
 * left <= right, reverse the nodes of the list from position left to position
 * right, and return the reversed list.
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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* now = head;

    ListNode* first_end;
    if (left == 1) {
      first_end = nullptr;
    } else {
      for (int i = 0; i < left - 2; i++) {
        now = now->next;
      }
      first_end = now;
    }

    ListNode* mid_end;
    if (first_end == nullptr) {
      mid_end = head;
    } else {
      mid_end = first_end->next;
    }

    ListNode* mid_first = reverse(mid_end, right - left + 1);

    ListNode* res;
    if (left == 1) {
      res = mid_first;
      mid_end->next = end_start_;
    } else {
      first_end->next = mid_first;
      mid_end->next = end_start_;
      res = head;
    }
    return res;
  }

  ListNode* reverse(ListNode* head, int size) {
    ListNode* prev = nullptr;
    ListNode* now = head;
    ListNode* next = head->next;

    ListNode* temp = head->next;
    for (int i = 0; i < size - 1; i++) {
      now->next = prev;
      if (next != nullptr) {
        temp = next->next;
      } else {
        break;
      }

      next->next = now;

      prev = now;
      now = next;
      next = temp;
    }
    end_start_ = temp;
    return now;
  }

 private:
  ListNode* end_start_ = nullptr;
};
