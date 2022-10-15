//{ Driver Code Starts

#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void append(struct Node** headRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)last = last->next;
	last->next = new_node;
}

void printList(struct Node *node)
{
    while(node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
} 

void alternatingSplitList(struct Node*); 

struct Node* a;
struct Node* b;

int main()
{
    int test;
    cin>>test;
    
    while(test--)
    {
        a=b=NULL;
        struct Node* head = NULL;
        
        
        int n, k;
        cin>>n;
        
        while(n--)
        {
            cin>>k;
            append(&head, k);
        }
        
        alternatingSplitList(head);
        printList(a);
        printList(b);
    }
    return 0;
}




// } Driver Code Ends


/*
structure of node is as
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


/*
These are global variables to store heads of split lists
struct Node* a; //store head of first list
struct Node* b; //store head of second list

*/

void alternatingSplitList(struct Node* head) 
{
    //Your code here
    if(!head){
        a = NULL;
        b = NULL;
        return;
    }
    if(!head->next){
        a = head;
        b = NULL;
        return;
    }
    a = NULL, b = NULL;
    Node *cur1 = NULL, *cur2 = NULL;
    int p = 0;
    while(head){
        if(p%2 == 0){
            if(a == NULL){
                a = head;
                cur1 = a;
            }
            else{
                cur1->next = head;
                cur1 = cur1->next;
            }
        }
        else{
            if(b == NULL){
                b = head;
                cur2 = b;
            }
            else{
                cur2->next = head;
                cur2 = cur2->next;
            }
        }
        p++;
        head = head->next;
    }
    cur1->next = NULL;
    cur2->next = NULL;
}

