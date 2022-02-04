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
    bool b=true;
    void find(TreeNode* p, TreeNode* q){
        if(p==nullptr&&q==nullptr) return;
        if(p==nullptr||q==nullptr){
            b=false;
            return;
        }
        if(p->val!=q->val) b=false;
        find(p->left,q->right);
        find(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        find(root,root);
        return b;
    }
};