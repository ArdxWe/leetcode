/* Given the head of a linked list and a value x, partition it such that all
 * nodes less than x come before nodes greater than or equal to x. You should
 * preserve the original relative order of the nodes in each of the two
 * partitions.
 */

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    if (head == nullptr) return nullptr;
    ListNode* res = nullptr;
    ListNode* now = head;
    ListNode* small = nullptr;
    ListNode* big = nullptr;
    ListNode* big_head = nullptr;

    ListNode* temp;

    while (now != nullptr) {
      temp = now->next;
      if (now->val >= x) {
        if (big_head == nullptr) {
          big_head = now;
          big = now;
          now->next = nullptr;
        } else {
          big->next = now;
          big = now;
          now->next = nullptr;
        }
      } else {
        if (res == nullptr) {
          res = now;
          small = now;
          now->next = nullptr;
        } else {
          small->next = now;
          small = now;
          now->next = nullptr;
        }
      }
      now = temp;
    }
    if (small == nullptr) {
      return big_head;
    }
    small->next = big_head;
    return res;
  }
};
