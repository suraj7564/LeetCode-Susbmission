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
    int serch(vector<int>& in,int x){
        for(int i=0;i<in.size();i++){
            if(in[i]==x) return i;
        }
        return 0;
    }
    TreeNode* find(vector<int>& pre,vector<int>& in,int &idx,int st,int end){
        if(st>end) return NULL;
        
        TreeNode* temp = new TreeNode(pre[idx++]);
        if(st==end){
            return temp;
        }
        int m = serch(in,temp->val);
        temp->left = find(pre,in,idx,st,m-1);
        temp->right = find(pre,in,idx,m+1,end);
        
        return temp;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        int idx = 0;
        return find(pre,in,idx,0,n-1);
    }
};