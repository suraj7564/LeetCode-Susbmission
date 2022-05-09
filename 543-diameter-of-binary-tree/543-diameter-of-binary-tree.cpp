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
        
        int lh = find(root->left,ans)+1;
        int rh = find(root->right,ans)+1;
        
        ans = max(ans,rh+lh-1);
        
        return max(rh,lh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        find(root,ans);
        return ans-1;
    }
};