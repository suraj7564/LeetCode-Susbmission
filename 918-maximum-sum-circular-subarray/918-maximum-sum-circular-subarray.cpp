class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN,sum=0,totalsum=0;
        for(auto &x:nums){
            sum+=x;
            ans=max(ans,sum);
            sum=max(0,sum);
            totalsum+=x;
            x=-x;
        }
        if(ans<0) return ans;
        int ans1=INT_MIN;
        sum=0;
        for(auto x:nums){
            sum+=x;
            ans1=max(ans1,sum);
            sum=max(0,sum);
        }
        return max({ans,ans1+totalsum});
    }
};