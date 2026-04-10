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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        

        //Iniitialize variables
        ListNode* dummy = new ListNode(0,head);
        //dummy->next = head;
        ListNode* l = dummy;
        ListNode* r = dummy;
        
        //maintain a distance of N (input variable)
        while(n>0 && r->next != nullptr){
            n--;
            r = r->next;
        }
        
        
        //traverse to the end of the list
        while(r->next != nullptr){
            l = l->next;
            r = r->next;
        }

        //delete the node
        l->next = l->next->next;
        
        return dummy->next;
        
    }
};
