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
    TreeNode* lca(TreeNode* root,TreeNode* a,TreeNode* b){
        if(!root) return root;
        
        if(root==a||root==b) return root;
        
        TreeNode* l = lca(root->left,a,b);
        TreeNode* r = lca(root->right,a,b);
        
        if(l&&r) return root;
        if(l) return l;
        return r;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return root;
        vector<TreeNode*> cur;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*> c;
            int n = q.size();
            while(n-->0){
                auto t = q.front();
                q.pop();
                c.push_back(t);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(q.empty()) cur = c;
        }
        TreeNode *ans = cur[0];
        for(int i=1;i<cur.size();i++){
            ans = lca(root,ans,cur[i]);
        }
        return ans;
    }
};