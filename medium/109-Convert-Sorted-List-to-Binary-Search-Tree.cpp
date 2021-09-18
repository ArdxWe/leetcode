/* Given the head of a singly linked list where elements are sorted in ascending
 * order, convert it to a height balanced BST. For this problem, a
 * height-balanced binary tree is defined as a binary tree in which the depth of
 * the two subtrees of every node never differ by more than 1.
 */

#include <cassert>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    if (head->next == nullptr) {
      return new TreeNode(head->val);
    }

    ListNode* medium_prev = getMediumPrev(head);
    ListNode* medium = medium_prev->next;
    assert(medium != nullptr);
    ListNode* medium_next = medium->next;

    TreeNode* res = new TreeNode(medium->val);
    medium_prev->next = nullptr;  // split

    res->left = sortedListToBST(head);
    res->right = sortedListToBST(medium_next);
    return res;
  }

  // bigger than 2
  // 2n + 1 return n, 2n return n
  ListNode* getMediumPrev(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = nullptr;

    assert(head != nullptr && head->next != nullptr);
    fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr &&
           fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};
