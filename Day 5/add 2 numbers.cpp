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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* result = ans;
        int carry = 0;
        while(l1 || l2){
            int num = l1->val + l2->val + carry;
            ListNode* temp = new ListNode(num%10);
            ans->next = temp;
            ans = ans->next;
            if(num > 9) carry=1;
            else carry = 0;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int num = l1->val + carry;
            ListNode* temp = new ListNode(num%10);
            ans->next = temp;
            ans = ans->next;
            if(num > 9) carry=1;
            else carry = 0;
            l1 = l1->next;
        }
        while(l2){
            int num = l2->val + carry;
            ListNode* temp = new ListNode(num%10);
            ans->next = temp;
            ans = ans->next;
            if(num > 9) carry=1;
            else carry = 0;
            l2 = l2->next;
        }

        if(carry == 1) {
            ListNode* temp = new ListNode(1);
            ans->next = temp;
        }

        return result->next;
    }
};