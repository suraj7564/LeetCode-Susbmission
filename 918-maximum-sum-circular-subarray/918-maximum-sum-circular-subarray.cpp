class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN,sum=0,totalsum=0;
        int ans1=INT_MAX,sum1=0;
        for(auto &x:nums){
            sum+=x;
            ans=max(ans,sum);
            sum=max(0,sum);
            totalsum+=x;
            sum1+=x;
            ans1=min(ans1,sum1);
            sum1=min(0,sum1);
        }
        if(ans<0) return ans;
        return max({ans,totalsum-ans1});
    }
};