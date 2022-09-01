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
    int ekfunction(TreeNode* root,int mx){
        if(root==nullptr){
            return 0;
        }
        if(root->val>=mx){
            return 1+ekfunction(root->left,root->val)+ekfunction(root->right,root->val);
        }
        return ekfunction(root->left,mx)+ekfunction(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return ekfunction(root,root->val);
    }
};