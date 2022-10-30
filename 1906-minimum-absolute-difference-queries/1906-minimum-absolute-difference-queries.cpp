class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> m(nums.size()+1);
        vector<int> cnt(101, 0);
        m[0] = cnt;
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
            m[i+1] = cnt;
        }
        vector<int> res;
        for(auto x:queries){
            int pre = -1000;
            int ans = 1000;
            for(int i=0;i<=100;i++){
                int cur = m[x[1]+1][i] - m[x[0]][i];
                if(cur>0){
                    ans = min(ans, i - pre);
                    pre = i;
                }
            }
            if(ans >= 1000) res.push_back(-1);
            else res.push_back(ans);
        }
        return res;
    }
};