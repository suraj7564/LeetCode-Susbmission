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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        long long ans=1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long long l=q.front().second;
            long long r=q.back().second;
            ans=max(ans,r-l+1);
            while(n-->0){
                TreeNode* curNode = q.front().first;
                int cur = q.front().second;
                q.pop();
                long long curIdx = cur-l;
                if(curNode->left){
                    q.push({curNode->left,(2LL*(curIdx)+1LL)});
                }
                if(curNode->right){
                    q.push({curNode->right,(2LL*(curIdx)+2LL)});
                }
            }
        }
        return ans;
    }
};