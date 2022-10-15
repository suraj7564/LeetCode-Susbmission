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
class Solution
{
public:
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
    void sortList(Node** head)
    {
        Node *cur = *head, *a, *b;
        if(cur == NULL || cur->next == NULL) return;
        split(cur, &a, &b);
        sortList(&a);
        sortList(&b);
        *head = merge(a, b);
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
		ob.sortList(&head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends