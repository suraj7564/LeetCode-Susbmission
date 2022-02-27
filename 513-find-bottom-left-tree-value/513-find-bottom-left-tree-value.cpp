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
    int findBottomLeftValue(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            bool b=true;
            while(n-->0){
                auto t = q.front();
                q.pop();
                if(b){
                    ans=t->val;
                    b=false;
                }
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return ans;
    }
};