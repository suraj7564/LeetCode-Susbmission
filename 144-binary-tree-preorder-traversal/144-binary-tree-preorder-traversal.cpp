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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur=root;
        stack<TreeNode*> s1;
        while(!s1.empty()||cur!=NULL){
            if(cur==nullptr){
                cur=s1.top()->right;
                s1.pop();
            }
            else{
                ans.push_back(cur->val);
                s1.push(cur);
                cur=cur->left;
            }
        }
        return ans;
    }
};