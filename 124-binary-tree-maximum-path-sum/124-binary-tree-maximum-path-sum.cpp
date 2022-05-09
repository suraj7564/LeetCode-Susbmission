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
    int find(TreeNode* root,int &ans){
        if(!root) return 0;
        
        int lsum = max(0,find(root->left,ans));
        int rsum = max(0,find(root->right,ans));
        
        ans = max(ans,lsum+rsum+root->val);
        
        return max(lsum,rsum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        
        int ans = INT_MIN;
        find(root,ans);
        
        return ans;
    }
};