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
    void find(TreeNode* root, int &ans, vector<int> cnt){
        if(!root) return;
        
        cnt[root->val]++;
        if(!root->left && !root->right){
            int c = 0;
            for(int i=0;i<10;i++){
                if(cnt[i]%2) c++;
            }
            if(c<=1) ans++;
        }
        
        find(root->left, ans, cnt);
        find(root->right, ans, cnt);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        vector<int> cnt(10, 0);
        find(root, ans, cnt);
        return ans;
    }
};