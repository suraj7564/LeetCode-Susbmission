//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
    Node* lca(Node* root, int first, int second){
        if(!root) return root;
        
        if(root->data==first || root->data==second) return root;
        
        Node* l = lca(root->left, first, second);
        Node* r = lca(root->right, first, second);
        
        if(l&&r) return root;
        
        if(l) return l;
        
        return r;
    }
    void findTurn(int pre, int curTurn, Node* root, int &data, int &turn){
        if(!root) return;
        
        
        
        if(root->data == data){
            turn = curTurn;
            return;
        }
        if(pre){
            if(pre==-1){
                findTurn(-1, curTurn, root->left, data, turn);
                findTurn(1, curTurn+1, root->right, data, turn);
            }
            else{
                findTurn(-1, curTurn+1, root->left, data, turn);
                findTurn(1, curTurn, root->right, data, turn); 
            }
        }
        else{
            findTurn(-1, curTurn, root->left, data, turn);
            findTurn(1, curTurn, root->right, data, turn);
        }
    }
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
      auto Lca = lca(root, first, second);
      //cout<<Lca->data<<endl;
      int x = 0, y = 0;
      findTurn(0, 0, Lca, first, x);
      findTurn(0, 0, Lca, second, y);
      //cout<<x<<" "<<y<<endl;
      if(Lca->data==first||Lca->data==second) return (x+y==0 ? -1 : x+y);
      return x+y+1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends