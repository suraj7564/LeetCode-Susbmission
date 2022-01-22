// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* h1, Node* h2)  
{  
    Node* ans = new Node(-1);
    Node* temp = ans;
    int x;
    while(h1&&h2){
        if(h1->data<=h2->data){
            x=h1->data;
            h1=h1->next;
        }
        else{
            x=h2->data;
            h2=h2->next;
        }
        Node* tt = new Node(x);
        temp -> next = tt;
        temp=temp->next;
    }
    while(h1){
        Node* tt = new Node(h1->data);
        h1=h1->next;
        temp -> next = tt;
        temp=temp->next;
    }
    while(h2){
        Node* tt = new Node(h2->data);
        h2=h2->next;
        temp -> next = tt;
        temp=temp->next;
    }
    return ans->next;
}  