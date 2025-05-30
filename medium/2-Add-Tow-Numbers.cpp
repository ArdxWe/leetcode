/* You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.You may assume the two numbers do not contain any leading zero, except
 * the number 0 itself.
 * Example 1:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * Example 2:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * Example 3:
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * Constraints:
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have leading
 * zeros.
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = nullptr;

    if (l1 == nullptr && l2 == nullptr) {
      return res;
    }
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }

    int sum = 0;  // The sum of the elements of a linked lists
    int value = 0;
    int overflow = 0;

    ListNode* entry = nullptr;
    while (l1 != nullptr || l2 != nullptr) {
      int l1_value = 0;
      int l2_value = 0;
      if (l1 == nullptr) {
        l2_value = l2->val;
        l2 = l2->next;
      } else if (l2 == nullptr) {
        l1_value = l1->val;
        l1 = l1->next;
      } else {
        l1_value = l1->val;
        l2_value = l2->val;
        l1 = l1->next;
        l2 = l2->next;
      }

      sum = l1_value + l2_value + overflow;
      value = sum % 10;
      overflow = sum / 10;

      ListNode* now = new ListNode(value);
      if (entry != nullptr) {
        entry->next = now;
      } else {
        res = now;
      }
      entry = now;
    }

    if (overflow != 0) {
      ListNode* now = new ListNode(overflow);
      entry->next = now;
    }

    return res;
  }
};