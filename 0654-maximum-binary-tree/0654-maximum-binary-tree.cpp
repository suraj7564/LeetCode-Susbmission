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
    TreeNode *solve(int l, int r, vector<int>& nums){
        if(l>r) return NULL;
        int idx = l;
        for(int i=l;i<=r;i++){
            if(nums[idx] < nums[i]){
                idx = i;
            }
        }
        TreeNode *root = new TreeNode(nums[idx]);
        root -> left = solve(l, idx-1, nums);
        root -> right = solve(idx+1, r, nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(0, nums.size()-1, nums);
    }
};