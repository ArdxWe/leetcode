/* Given the head of a singly linked list, sort the list using insertion sort,
 * and return the sorted list's head. The steps of the insertion sort algorithm:
 * Insertion sort iterates, consuming one input element each repetition and
 * growing a sorted output list. At each iteration, insertion sort removes one
 * element from the input data, finds the location it belongs within the sorted
 * list and inserts it there. It repeats until no input elements remain. The
 * following is a graphical example of the insertion sort algorithm. The
 * partially sorted list (black) initially contains only the first element in
 * the list. One element (red) is removed from the input data and inserted
 * in-place into the sorted list with each iteration.
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
  ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* res = nullptr;
    ListNode* now = head;
    ListNode* temp;

    while (now != nullptr) {
      temp = now->next;
      res = insert(res, now);
      now = temp;
    }
    return res;
  }

  ListNode* insert(ListNode* list, ListNode* item) {
    if (list == nullptr) {
      item->next = nullptr;
      return item;
    }

    ListNode* pos = nullptr;
    ListNode* now = list;

    while (now != nullptr && now->val < item->val) {
      pos = now;
      now = now->next;
    }

    if (pos == nullptr) {
      item->next = list;
      return item;
    } else {
      pos->next = item;
      item->next = now;
      return list;
    }
  }
};
