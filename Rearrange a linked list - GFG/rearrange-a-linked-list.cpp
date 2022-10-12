//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       if(!head || !head->next) return;
       Node *even = NULL, *cur1, *odd = NULL, *cur2;
       int i = 0;
       Node *cur = head;
       while(cur){
           if(i%2 == 0){
               if(odd == NULL){
                   odd = cur;
                   cur2 = odd;
               }
               else{
                   cur2->next = cur;
                   cur2 = cur2->next;
               }
           }
           else{
               if(even == NULL){
                   even = cur;
                   cur1 = even;
               }
               else{
                   cur1->next = cur;
                   cur1 = cur1->next;
               }
           }
           i++;
           cur = cur->next;
       }
       cur1->next = NULL;
       cur2->next = even;
       head = odd;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends