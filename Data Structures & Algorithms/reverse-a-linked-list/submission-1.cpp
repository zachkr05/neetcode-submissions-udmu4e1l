/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       return reverseList(head,nullptr);
    }  

private:

    ListNode* reverseList(ListNode* curr, ListNode* prev){
        if(curr == nullptr){
            return prev;
        }
        ListNode* next = curr->next;
        curr->next = prev;
        return reverseList(next, curr);
    }
};
