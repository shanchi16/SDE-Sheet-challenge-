/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detect(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast!=NULL && fast->next != NULL){

                fast = fast->next->next;
                slow = slow->next;
            if(fast == slow){
                while(slow != prev){
                slow = slow->next;
                prev = prev->next;
                
                }
                return slow;
            }
        }
        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* slow = detect(head);
        return slow;
    }
};