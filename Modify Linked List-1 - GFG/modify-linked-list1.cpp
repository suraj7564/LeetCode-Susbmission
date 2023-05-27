//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
class Solution{
    public:
    Node* reverse(Node *head){
        Node *pre = NULL, *cur = head, *nxt;
        while(cur){
            nxt = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        if(!head || !head -> next) return head;
        Node *copy = NULL, *temp = head, *cur = NULL;
        while(temp){
            if(copy == NULL){
                copy = new Node(temp->data);
                cur = copy;
            }
            else{
                cur -> next = new Node(temp -> data);
                cur = cur -> next;
            }
            temp = temp->next;
        }
        Node *rev = reverse(head);
        cur = rev;
        Node *slow = copy, *fast = copy;
        while(fast && fast -> next){
            cur -> data = cur -> data - slow -> data;
            slow = slow -> next;
            cur = cur -> next;
            fast = fast -> next -> next;
        }
        return rev;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends