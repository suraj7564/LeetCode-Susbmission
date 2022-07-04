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
    bool check(TreeNode* root,TreeNode* l,TreeNode* r){
        if(!root) return true;
        
        if(l&&l->val>=root->val||r&&r->val<=root->val) return false;
        
        return (check(root->left,l,root)&&check(root->right,root,r));
    }
    bool isValidBST(TreeNode* root) {
        return check(root,NULL,NULL);
    }
};