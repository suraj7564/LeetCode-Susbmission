class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            cur = max(cur,i+nums[i]);
            if(i>=cur&&i!=n-1) return false;
        }
        return true;
    }
};