//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node *merge(Node* a, Node *b){
        Node* result = NULL;
 
        /* Base cases */
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);
     
        /* Pick either a or b, and recur */
        if (a->data <= b->data) {
            result = a;
            result->next = merge(a->next, b);
        }
        else {
            result = b;
            result->next = merge(a, b->next);
        }
        return (result);
    }
    void split(Node *head,Node **a, Node **b){
        Node* slow = head, *fast = head->next;
        while(fast){
            fast = fast->next;
            if(fast){
                slow = slow->next;
                fast = fast->next;
            }
        }
        *a = head;
        *b = slow->next;
        //cout<<head->data<<" "<<slow->next->data<<endl;
        slow->next = NULL;
    }
    void sort(Node **head){
        Node *cur = *head, *a, *b;
        if(cur == NULL || cur->next == NULL) return;
        split(cur, &a, &b);
        sort(&a);
        sort(&b);
        *head = merge(a, b);
    }
    Node* mergeSort(Node* head) {
        sort(&head);
        return head;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends