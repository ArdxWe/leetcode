/*
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered
 * list. The first node is considered odd, and the second node is even, and so
 * on. Note that the relative order inside both the even and odd groups should
 * remain as it was in the input. You must solve the problem in O(1) extra space
 * complexity and O(n) time complexity.
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
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode* first_head = head;
    ListNode* first_now = first_head;

    ListNode* second_head = head->next;
    ListNode* second_now = second_head;

    head = head->next->next;
    bool first = true;

    while (head != nullptr) {
      if (first) {
        first_now->next = head;
        first_now = head;
        first = false;
      } else {
        second_now->next = head;
        second_now = head;
        first = true;
      }
      head = head->next;
    }

    second_now->next = nullptr;
    first_now->next = second_head;
    return first_head;
  }
};
