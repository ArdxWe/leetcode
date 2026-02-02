class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        if (n <= 0) return head;

        ListNode* current = head;
        ListNode* x = head;

        for (int i =0; i <= n; i++) {
            if (x == nullptr) {
                if (i==n) {
                    return head->next;
                }
                return nullptr;
            }
            x = x->next;
        }

        while (x != nullptr) {
            current = current->next;
            x = x->next;
        }

        if (current->next == nullptr) {
            return nullptr;
        }

        current->next = current->next->next;
        return head;
    }
};
