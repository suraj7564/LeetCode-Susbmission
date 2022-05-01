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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,vector<int>> m;
        while(!q.empty()){
            int sz = q.size();
            vector<pair<int,int>> temp;
            while(sz-->0){
                auto curNode = q.front().first;
                int line = q.front().second;
                q.pop();
                temp.push_back({curNode->val,line});
                if(curNode->left) q.push({curNode->left,line-1});
                if(curNode->right) q.push({curNode->right,line+1});
            }
            sort(temp.begin(),temp.end());
            for(auto x:temp){
                m[x.second].push_back(x.first);
            }
        }
        for(auto x:m){
            vector<int> temp = x.second;
            //sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
    	return ans;
    }
};