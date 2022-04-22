class Solution {
public:
    void solve(vector<int>& nums,vector<int>& cur,map<int,int>& m,vector<vector<int>>& ans){
        if(cur.size()==nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==0){
                cur.push_back(nums[i]);
                m[nums[i]] = 1;
                solve(nums,cur,m,ans);
                m[nums[i]] = 0;
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        map<int,int> m;
        solve(nums,cur,m,ans);
        return ans;
    }
};