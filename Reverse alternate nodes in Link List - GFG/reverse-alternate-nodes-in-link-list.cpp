//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node *reverse(Node *a){
        Node *cur = a, *pre = NULL, *nxt;
        while(cur){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        if(!odd || !odd->next) return;
        Node *h1 = NULL, *p1, *h2 = NULL, *p2;
        int cur = 0;
        while(odd){
            if(cur%2 == 0){
                if(h1 == NULL){
                    h1 = odd;
                    p1 = h1;
                }
                else{
                    p1->next = odd;
                    p1 = p1->next;
                }
            }
            else{
                if(h2 == NULL){
                    h2 = odd;
                    p2 = h2;
                }
                else{
                    p2->next = odd;
                    p2 = p2->next;
                }
            }
            cur++;
            odd = odd->next;
        }
        p2->next = NULL;
        h2 = reverse(h2);
        p1->next = h2;
        odd = h1;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends