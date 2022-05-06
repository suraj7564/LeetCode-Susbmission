// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    vector<int> v1,v2;int x,y;
    void findPath(Node* root,vector<int> ans){
        if(!root) return ;
        ans.push_back(root->data);
        if(root->data==x) v1=ans;
        if(root->data==y) v2=ans;
        findPath(root->left,ans);
        findPath(root->right,ans);
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       vector<int> a,b;
       x=n1,y=n2;
       findPath(root,a);
    //   for(auto x:v1){
    //       cout<<x<<" ";
    //   }
    //   cout<<endl;
    //   for(auto x:v2){
    //       cout<<x<<" ";
    //   }
    //   cout<<endl;
       int ans = -1;
       for(int i=0,j=0;i<v1.size()&&j<v2.size();i++,j++){
           if(v1[i]==v2[j]) ans = v1[i];
           else break;
       }
       //cout<<ans<<" ";
       Node *res=root;
       queue<Node*> q;
       q.push(res);
       while(!q.empty()){
           auto t = q.front();
           q.pop();
           if(t->data==ans) return t;
           if(t->left) q.push(t->left);
           if(t->right) q.push(t->right);
       }
        return NULL;
    }
};

// { Driver Code Starts.

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}
  // } Driver Code Ends