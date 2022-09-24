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
    int x;
    void find(vector<vector<int>>& ans,TreeNode* root,vector<int>& v,int sum){
        if(root->left==NULL&&root->right==NULL){
            if(sum==x){
                ans.push_back(v); 
            }
            return;
        }
        if(root->left){
            v.push_back(root->left->val);
            sum+=root->left->val;
            find(ans,root->left,v,sum);
            sum=sum-v[v.size()-1];
            v.pop_back();
        }
        if(root->right){
            v.push_back(root->right->val);
            sum+=root->right->val;
            find(ans,root->right,v,sum);
            sum=sum-v[v.size()-1];
            v.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        x=targetSum;
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> v;
        int sum=root->val;
        v.push_back(root->val);
        find(ans,root,v,sum);
        return ans;
    }
};