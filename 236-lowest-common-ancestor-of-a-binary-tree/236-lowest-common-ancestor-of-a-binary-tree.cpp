/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(root->val==p->val||root->val==q->val) return root;
        
        TreeNode* leftLca = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightLca = lowestCommonAncestor(root->right,p,q);
        
        if(leftLca&&rightLca) return root;
        
        if(leftLca) return leftLca;
        return rightLca; 
    }
};