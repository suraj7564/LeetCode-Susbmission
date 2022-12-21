//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:
    Node *reverse(Node *head){
        if(!head || !head->next) return head;
        
        Node *cur = head, *pre = NULL, *nxt;
        while(cur){
            nxt = cur->next;
            cur -> next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    Node* sortList(Node* head)
    {
        Node *pos = NULL, *neg = NULL;
        Node *t1 = NULL, *t2 = NULL;
        while(head){
            if(head -> data >= 0){
                if(t1 == NULL){
                    //cout<<1<<" "<<head->data<<endl;
                    pos = head;
                    t1 = pos;
                }
                else{
                    //cout<<2<<" "<<head->data<<endl;
                    t1->next = head;
                    t1 = t1 -> next;
                }
            }
            else{
                if(t2 == NULL){
                    //cout<<3<<" "<<head->data<<endl;
                    neg = head;
                    t2 = neg;
                }
                else{
                    //cout<<4<<" "<<head->data<<endl;
                    t2->next = head;
                    t2 = t2 -> next;
                }
            }
            head = head -> next;
        }
        if(t1) t1->next = NULL;
        if(t2) t2->next = NULL;
        
        neg = reverse(neg);
        
        Node *temp = neg;
        while(temp && temp->next) temp = temp -> next;
        
        if(!temp) return pos;
        
        temp -> next = pos;
        return neg;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends