//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    int ans;
    
    void addValues(Node *root, int k)
    {
        if(k < 0 || root == NULL)
        return;
        
        ans += root->data;
        addValues(root->left, k - 1);
        addValues(root->right, k - 1);
    }
    
    int dfs(Node *root, int home, int k)
    {
        if(root == NULL)
        return -1;
        
        if(root->data == home)
        {
            addValues(root, k);
            return k - 1;
        }
        
        int val1 = dfs(root->left, home, k);
        int val2 = dfs(root->right, home, k);
        
        if(val1 >= 0)
        {
            ans += root->data;
            addValues(root->right, val1 - 1);
            return val1 - 1;
        }
        
        if(val2 >= 0)
        {
            ans += root->data;
            addValues(root->left, val2 - 1);
            return val2 - 1;
        }
        return -1;
    }
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        ans = 0;
        dfs(root, home, k);
        return ans;
    }



};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends