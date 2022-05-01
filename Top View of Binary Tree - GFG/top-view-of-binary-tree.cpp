// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        if(!root) return {};
    	vector<int> ans;
    	queue<pair<Node *,int>> q;
    	q.push({root,0});
    	vector<vector<pair<int,int>>> temp;
    	while(!q.empty()){
    		vector<pair<int,int>> cur;
    		int sz = q.size();
    		while(sz-->0){
    			auto curNode = q.front().first;
    			int line = q.front().second;
    			q.pop();
    			cur.push_back({line,curNode->data});
    			if(curNode->left) q.push({curNode->left,line-1});
    			if(curNode->right) q.push({curNode->right,line+1});
    		}
    		temp.push_back(cur);
    	}
    	vector<pair<int,int>> ans1;
    	int mn = 1e9 , mx = -1;
    	for(int i=0;i<temp.size();i++){
    		int curMn = 1e9 , curMx = -1;
    		for(int j=0;j<temp[i].size();j++){
    			curMn = min(curMn,temp[i][j].first);
    			curMx = max(curMx,temp[i][j].first);
    			int curr = temp[i][j].first;
    			if(curr<mn){
    				ans1.push_back(temp[i][j]);
    			}
    			else if(curr>mx){
    				ans1.push_back(temp[i][j]);
    			}
    		}
    		mn = min(curMn,mn);
    		mx = max(curMx,mx);
    	}
    	sort(ans1.begin(),ans1.end());
    	for(auto x:ans1){
    		ans.push_back(x.second);
    	}
    	return ans;
    }

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends