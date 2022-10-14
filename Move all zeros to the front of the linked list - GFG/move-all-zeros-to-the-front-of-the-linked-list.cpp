//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
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

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void moveZeroes(struct Node **head);

// function to displaying nodes
void display(struct Node *head) {
    while (head != NULL) {
	    cout << head->data << " ";
	    head = head->next;
    }
    cout <<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q;
        vector<int> v;
        struct Node *Head=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>q;
            v.push_back(q);
        }
        reverse(v.begin(),v.end());
        for(auto q:v)
            push(&Head,q);
        moveZeroes(&Head);
        display(Head);

    }
}

// } Driver Code Ends


//User function Template for C++
/* Linked List Node structure
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
// Move Zeros to the front of the list
void moveZeroes(struct Node **head)
{
    //Your code here
    Node *ans = NULL, *cur = NULL;
    Node *ans1 = NULL, *cur1 = NULL;
    Node *t = *head;
    while(t){
        if(t->data == 0){
            if(ans == NULL){
                ans = t;
                cur = ans;
            }
            else{
                cur->next = t;
                cur = cur->next;
            }
        }
        else{
            if(ans1 == NULL){
                ans1 = t;
                cur1 = ans1;
            }
            else{
                cur1->next = t;
                cur1 = cur1->next;
            }
        }
        t = t->next;
    }
    if(!cur){
        *head = ans1;
        return;
    }
    if(!cur1){
        *head = ans;
        return;
    }
    if(cur1)
        cur1->next = NULL;
    cur->next = ans1;
    *head = ans;
}