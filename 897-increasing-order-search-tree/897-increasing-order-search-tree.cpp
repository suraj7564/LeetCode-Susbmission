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
    vector<int> v;
    TreeNode *root1;
    void pre(TreeNode* root){
        if(root==NULL) return;
        v.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        pre(root);
        sort(v.begin(),v.end());
        root1=new TreeNode(v[0]);
        TreeNode *temp=root1;
        for(int i=1;i<v.size();i++){
            TreeNode *t=new TreeNode(v[i]);
            temp->right=t;
            temp=temp->right;
        }
        return root1;
    }
};