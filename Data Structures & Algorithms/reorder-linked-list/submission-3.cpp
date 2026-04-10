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
    void reorderList(ListNode* head) {
        //find the half way between the list

        if(head->next == nullptr){
            return;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;
        
        //split the list into halves 
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; // cut the list

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // save next
            curr->next = prev;               // reverse pointer
            prev = curr;                     // advance prev
            curr = nextTemp;                 // advance curr
        }


        //printf("%d", curr->next->val);
        //remap the nodes accordingly
        ListNode* h1 = head;
        ListNode* h2 = prev;
        printf("%d", h2->val);
        while(h2 != nullptr){
            
            ListNode* temp_1 = h1->next;
            h1->next = h2;
            ListNode* temp_2 = h2->next;
            h2->next = temp_1;
            h1 = temp_1;
            h2 = temp_2;
        }

    }
};
