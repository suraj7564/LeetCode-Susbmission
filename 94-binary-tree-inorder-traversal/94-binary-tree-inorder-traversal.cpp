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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> s1;
        while(!s1.empty()||root){
            if(root){
                s1.push(root);
                root = root->left;
            }
            else{
                TreeNode *temp = s1.top();
                s1.pop();
                ans.push_back(temp->val);
                root = temp->right;
            }
        }
        return ans;
    }
};