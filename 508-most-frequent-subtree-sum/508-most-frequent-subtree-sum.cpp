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
    int find(TreeNode *root,map<int,int>& m,int &mx){
        if(!root) return 0;
        
        int l = find(root->left,m,mx);
        int r = find(root->right,m,mx);
        
        int total = l+r+root->val;
        m[total]++;
        mx = max(mx,m[total]);
        
        return total;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return {};
        map<int,int> m;
        int mx = 0;
        find(root,m,mx);
        vector<int> ans;
        for(auto x:m){
            if(x.second==mx) ans.push_back(x.first);
        }
        return ans;
    }
};