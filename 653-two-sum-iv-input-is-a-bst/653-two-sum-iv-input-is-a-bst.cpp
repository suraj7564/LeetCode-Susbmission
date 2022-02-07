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
    bool findTarget(TreeNode* root, int k) {
        map<int,int> m;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n-->0){
                auto t=q.front();
                q.pop();
                if(m.count(k-t->val)) return true;
                m[t->val]=1;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return false;
    }
};