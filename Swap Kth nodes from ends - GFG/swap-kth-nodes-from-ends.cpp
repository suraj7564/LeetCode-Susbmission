//{ Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    Node *fast = head, *slow = head;
    Node *dumy = new Node(0);
    dumy->next = head;
    Node *pre = dumy;
    for(int i=1;i<K&&fast;i++){
        pre = fast;
        fast = fast->next;
    }
    Node *pre1 = dumy;
    if(!fast) return head;
    fast = fast->next;
    while(fast){
        pre1 = slow;
        slow = slow->next;
        fast = fast->next;
    }
    //cout<<pre1->data<<" "<<pre->data<<endl;
    Node *cur1 = pre1->next;
    pre1->next = pre->next;
    pre->next = cur1;
    cur1 = pre1->next->next;
    pre1->next->next = pre->next->next;
    pre->next->next = cur1;
    return dumy->next;
}
