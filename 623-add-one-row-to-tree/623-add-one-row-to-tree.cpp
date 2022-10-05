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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *cur = new TreeNode(val);
            cur -> left = root;
            return cur;
        }
        if(!root) return root;
        int cnt = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            cnt++;
            int sz = q.size();
            while(sz-->0){
                auto t = q.front();
                q.pop();
                if(cnt == depth){
                    TreeNode *l = t->left, *r = t->right;
                    t->left = new TreeNode(val);
                    t->left->left = l;
                    t->right = new TreeNode(val);
                    t->right->right = r;
                }
                else{
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                }
            }
        }
        return root;
    }
};