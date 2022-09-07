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
    void find(TreeNode *root,string &ans){
        if(!root) return;
        ans += to_string(root->val);
        
        if(!root->left && !root->right) return;
        ans += '(';
        find(root->left, ans);
        ans += ')';
        if(!root->right) return;
        ans += '(';
        find(root->right, ans);
        ans += ')';
    }
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string ans = "";
        find(root, ans);
        return ans;
    }
};