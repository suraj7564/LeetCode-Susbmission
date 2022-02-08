class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans=INT_MIN,cur=0;
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            ans=max(cur,ans);
            cur=max(0,cur);
        }
        int n=nums.size();
        vector<int> suf=nums;
        for(int i=n-2;i>=0;i--){
            suf[i]+=suf[i+1];
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i],suf[i+1]);
        }
        cur=0;
        for(int i=0;i<n-2;i++){
            cur+=nums[i];
            ans=max(ans,cur+suf[i+2]);
        }
        return ans;
    }
};