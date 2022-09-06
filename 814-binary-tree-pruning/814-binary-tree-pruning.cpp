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
    bool help(TreeNode* root){
        if(root==NULL) return false;
        
        bool l=help(root->left);
        bool r=help(root->right);
        
        if(!l) root->left=NULL;
        if(!r) root->right=NULL;
        
        return (root->val==1)||l||r;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        bool b=help(root);
        if(!b) return NULL;
        
        return root;
    }
};