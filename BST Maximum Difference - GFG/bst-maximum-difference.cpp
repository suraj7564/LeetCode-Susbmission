//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int top = -1, t;
    Node *cur = NULL;
    void get(Node* root, int sum){
        if(!root) return;
        
        if(root->data == t){
            top = sum + t;
            cur = root;
            return;
        }
        if(root -> data > t)
            get(root->left, sum + root->data);
        else
            get(root->right, sum + root->data);
    }
    int dfs(Node* root){
        if(!root) return 1e9;
        if(!root->right && !root->left) return root->data;
        
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        
        return min(l , r) + root->data;
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int sum = 0;
        t = target;
        cur = NULL;
        get(root, sum);
        if(!cur) return -1;
        int down = dfs(cur);
        //cout<<top<<" "<<down<<endl;
        return top - down;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends