                                
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists
Node* sortTwoLinkedLists(Node* list1, Node* list2) {
    ListNode* temp = list1;
    if(!list1 ) return list2;
    if(!list2) return list1;
    else if(!list1 && !list2) return NULL;
    if(list1->val <= list2->val){
        list1 = list1->next;
    }
    else{
        temp = list2;
        list2 = list2->next;
    }
    ListNode* ans = temp;
    while(list1 && list2){
        if(list1->val <= list2->val){
            ans->next = list1;
            list1 = list1->next;
        }
        else{
            ans->next = list2;
            list2 = list2->next;
        }
        ans = ans->next;
    }

    while(list1){
        ans->next = list1;
        list1 = list1->next;
        ans = ans->next;
    }
    while(list2){
        ans->next = list2;
        list2 = list2->next;
        ans = ans->next;
    }

    return temp;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

int main() {
    // Example Linked Lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node* mergedList = sortTwoLinkedLists(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}
                                
                            