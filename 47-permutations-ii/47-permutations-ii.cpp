class Solution {
public:
    set<vector<int>> s1;
    void find(vector<int>& nums,int l,int r,vector<vector<int>>& ans){
        if(l==r){
            if(s1.find(nums)!=s1.end()) return;
            s1.insert(nums);
            ans.push_back(nums);
            return;
        }
        for(int i=l;i<=r;i++){
            swap(nums[l],nums[i]);
            find(nums,l+1,r,ans);
            swap(nums[l],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        s1.clear();
        find(nums,0,nums.size()-1,ans);
        return ans;
    }
};