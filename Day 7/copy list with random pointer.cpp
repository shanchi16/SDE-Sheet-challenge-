/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* curhead = new Node(-1);
        Node* curr = curhead;
        unordered_map<Node*, int> mp;

        // usually hmare pass nest pointer hota h bs
        // esme ek next pointer h dusra random jo ki kisi bhi random node in list ko point krega 

        Node* temp = head;
        while(temp){
            // ess loop m nodes bna li or next pointer bhi but ab random ko point krvana h 

            // creating a new node
            Node* t = new Node(temp->val);
            // point curhed-> to new node
            curhead->next = t;
            curhead = curhead->next;
            mp[curhead] = curhead->val;
            temp = temp->next;
        }

        curhead = curr->next;
        temp = head;
        Node* nextTemp;
        Node* nextcurr;

        while(curhead && temp){
            nextTemp = temp->next;
            temp->next = curhead;
            nextcurr = curhead->next;
            curhead->next = nextTemp;
            curhead = nextcurr;
            temp = nextTemp;
        }

        temp = head;
        
        while(temp ){
            if( temp->next){
                if(temp->random != NULL){
                    Node* ran = temp->random;
                    temp->next->random = ran->next;
                }
                else{
                    temp->next->random = temp->random;
                }
            }
            temp = temp->next ->next;
            
        }
        
        

        temp = head;    
        curhead = temp->next;
        while(temp && temp->next){
            temp->next = curhead->next;
            temp = temp->next;
            if(temp == NULL) {
                curhead->next = NULL;
            }else{
                curhead->next = temp->next;
                curhead = curhead->next;
            }
            
            

        }

        return curr->next;
    }
};