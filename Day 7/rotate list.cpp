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

    ListNode* rotateRight(ListNode* head, int k) {

        int cnt=1;
        ListNode* tail = head;
        while(tail && tail->next) {
            tail = tail->next;
            cnt++;
        } 
        cout<<cnt<< " ";
        if(k%cnt == 0) return head;
        tail->next = head;
        
        k=k%cnt;
        k = cnt-k;
        cout<<k<<" ";
        while(k>0){
            tail = tail->next;
            k--;
        }
        
        ListNode* result = tail->next;
        tail->next = NULL;
        
        return result;
    }
};