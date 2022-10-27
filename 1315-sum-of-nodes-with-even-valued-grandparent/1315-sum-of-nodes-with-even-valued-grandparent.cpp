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
    int sumEvenGrandparent(TreeNode* root, int p = -1, int gp = -1) {
        if(!root) return 0;
        int sum = 0;
        if(gp != -1 && gp%2 == 0){
            sum += root->val;
        }
        sum += sumEvenGrandparent(root->left, root->val, p);
        sum += sumEvenGrandparent(root->right, root->val, p);
        
        return sum;
    }
};