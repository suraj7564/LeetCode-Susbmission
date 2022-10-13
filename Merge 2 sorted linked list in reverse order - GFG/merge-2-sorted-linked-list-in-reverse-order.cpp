//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/
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
struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here
    node1 = reverse(node1);
    node2 = reverse(node2);
    
    Node *ans = newNode(0);
    Node *cur = ans;
    while(node1 && node2){
        if(node1->data>node2->data){
            cur->next = node1;
            cur = cur->next;
            node1 = node1->next;
        }
        else{
            cur->next = node2;
            cur =cur->next;
            node2 = node2->next;
        }
    }
    if(node1) cur->next = node1;
    if(node2) cur->next = node2;
    
    return ans->next;
}