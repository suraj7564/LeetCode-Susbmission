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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        int x;
        while(!q.empty()){
            int sz = q.size();
            while(sz-->0){
                auto t = q.front();
                x = t->val;
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(x);
        }
        return ans;
    }
};