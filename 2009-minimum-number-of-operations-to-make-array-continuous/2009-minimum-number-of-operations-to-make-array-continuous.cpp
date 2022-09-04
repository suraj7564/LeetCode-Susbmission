class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> t;
        t.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] != nums[i-1]){
                t.push_back(nums[i]);
            }
        }
        int ans = n;
        for(int i=0;i<t.size();i++){
            int idx = upper_bound(t.begin(), t.end(), t[i]+n-1)-t.begin();
            ans = min(ans, n - (idx-i));
        }
        return ans;
    }
};