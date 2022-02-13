class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int> > s1;
        int n=nums.size();
        int t=(1<<n);
        for(int i=0;i<=t;i++){
            vector<int> cur;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    cur.push_back(nums[j]);
                }
            }
            s1.insert(cur);
        }
        vector<vector<int>> ans;
        for(auto x:s1) ans.push_back(x);
        return ans;
    }
};