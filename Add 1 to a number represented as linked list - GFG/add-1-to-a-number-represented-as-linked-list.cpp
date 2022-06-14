// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
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

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

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
    Node* reverse(Node* head){
        if(!head||!head->next) return head;
        
        Node* nhead = reverse(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        
        return nhead;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* res = reverse(head);
        
        Node* temp = res;
        
        int carry = 1;
        Node* pre;
        while(temp){
            int d = temp->data+carry;
            temp->data = d%10;
            carry = d/10;
            pre = temp;
            temp = temp->next;
        }
        if(carry>0){
            pre->next = new Node(carry);
        }
        Node* ans = reverse(res);
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends