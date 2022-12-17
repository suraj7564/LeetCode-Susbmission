// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    map<int,int> mp;
    Node* find(int pre[],int in[],int &idx,int st,int end){
        if(st>end) return NULL;
        
        Node* root = new Node(pre[idx++]);
        
        if(st==end) return root;
        
        int mid = mp[root->data];
        root->left = find(pre, in, idx, st, mid-1);
        root->right = find(pre, in, idx, mid+1, end);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        for(int i=0;i<n;i++) mp[in[i]] = i;
        int idx = 0;
        
        return find(pre, in, idx, 0, n-1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends