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
    vector<int> find(TreeNode* root,int &ans){
        if(!root) return {0,INT_MAX,INT_MIN};
        
        auto left = find(root->left,ans);
        auto right = find(root->right,ans);
        
        if(left[2]<root->val&&root->val<right[1]){
            ans = max(ans,left[0]+right[0]+root->val);
            int mn = min(root->val,left[1]);
            int mx = max(root->val,right[2]);
            return {left[0]+right[0]+root->val,mn,mx};
        }
        else{
            return {0,INT_MIN,INT_MAX};
        }
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        find(root,ans);
        return ans;
    }
};