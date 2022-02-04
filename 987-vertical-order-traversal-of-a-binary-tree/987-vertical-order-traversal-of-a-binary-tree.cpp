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
    int l=100000,r1=0;
    map<pair<int,int>,vector<int> > m;
    void find(TreeNode* root,int r,int c){
        if(!root) return;
        m[{r,c}].push_back(root->val);
        l=min(l,c);
        r1=max(r1,c);
        //cout<<r<<" "<<c<<" "<<r1<<" "<<l<<endl;
        find(root->left,r+1,c-1);
        find(root->right,r+1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        l=100000,r1=0;
        find(root,0,0);
        //cout<<r1<<" "<<l<<endl;
        vector<vector<int>> ans(r1-l+1);
        for (auto &[i, j]: m) {
            sort(j.begin(), j.end());
            ans[i.second - l].push_back(i.first); //push each rwo
        }
        
        int col = l;
        for (vector<int> &v: ans) {
            sort(v.begin(), v.end()); //sort all rows
            vector<int> tmp = v;
            v.clear();
            
            //push sorted rows for each column in ans
            for (int r: tmp) {
                // v.push_back(mp[{r, col}]);
                for (int x: m[{r, col}])
                    v.push_back(x);
            }
            ++col;
        }        
        return ans;
    }
};