//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

// task is to complete this function
struct Node* arrange(Node *head);

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/
// task is to complete this function
// function should return head to the list after making 
// necessary arrangements
bool isVowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
    return 0;
}
struct Node* arrange(Node *head)
{
   //Code here
   Node *v = NULL, *pre1 = NULL;
   Node *c = NULL, *pre2 = NULL;
   
   while(head){
       if(isVowel(head->data)){
           if(v == NULL){
               v = head;
               pre1 = v;
           }
           else{
               pre1->next = head;
               pre1 = pre1->next;
           }
       }
       else{
           if(c == NULL){
               c = head;
               pre2 = c;
           }
           else{
               pre2->next = head;
               pre2 = pre2->next;
           }
       }
       head = head->next;
   }
   if(!pre2) return v;
   if(!pre1) return c;
   pre2->next = NULL;
   pre1->next = c;
   return v;
}
