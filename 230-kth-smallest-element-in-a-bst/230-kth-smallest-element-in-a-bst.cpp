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
    void help(TreeNode* root){
        if(!root) return;
        help(root->left);
        v.push_back(root->val);
        help(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        help(root);
        int ans=0;
        int cnt=1;
        sort(v.begin(),v.end());
        if(k==1) return v[0];
        int n=v.size();
        for(int i=1;i<n;i++){
            if(v[i]!=v[i-1]) cnt++;
            if(cnt==k){
                ans=v[i];
                break;
            }
        }
        return ans;   
    }
};