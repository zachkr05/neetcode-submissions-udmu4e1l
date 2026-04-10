class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return helper(head, nullptr);      // handles head == nullptr too
    }

private:
    static ListNode* helper(ListNode* curr, ListNode* prev) {
        if (!curr) return prev;            // prev is the new head
        ListNode* next = curr->next;
        curr->next = prev;
        return helper(next, curr);         // return the new head up the stack
    }
};
