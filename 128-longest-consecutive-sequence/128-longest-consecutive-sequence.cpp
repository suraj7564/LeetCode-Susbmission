class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int cnt=1;
        int ans=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==0){
                continue;
            }
            if(nums[i]-nums[i-1]==1){
                cnt++;
            }
            else cnt=1;
            ans=max(ans,cnt);
        }
        return ans;
    }
};