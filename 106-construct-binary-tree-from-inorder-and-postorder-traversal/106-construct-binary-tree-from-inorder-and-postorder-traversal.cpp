/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* find(vector<int>& post,vector<int>& in,int &idx,int st,int end){
        if(st>end) return NULL;
        
        TreeNode* temp = new TreeNode(post[idx--]);
        if(st==end){
            return temp;
        }
        int m = mp[temp->val];
        
        temp->right = find(post,in,idx,m+1,end);
        temp->left = find(post,in,idx,st,m-1);
        
        return temp;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        int idx = n-1;
        for(int i=0;i<n;i++){
            mp[in[i]] = i;
        }
        return find(post,in,idx,0,n-1);
    }
};