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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        // by traversing the slinked list twice i.e. which will help us counteract the difference of no of          nodes in 2 lists
        while(temp1 != temp2){
            // if(temp1!=NULL) temp1 = temp1->next;
            // else temp1 = headB; i.e pointing to the head of other linked list
            temp1 = temp1 ? temp1->next : headB;
            temp2 = temp2 ? temp2->next : headA;
            // if(temp2!=NULL) temp2 = temp2->next;
            // else temp2 = headA; i.e pointing to the head of other linked list
        }

        return temp1;
    }
};