class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        if(n<=1) return false;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        vector<int> dp(sum+1,0);
        dp[0] = 1;
        for(int i=1;i<n;i++){
            for(int j=sum;j>=nums[i];j--){
                if(dp[j-nums[i]]){
                    dp[j] |= (dp[j-nums[i]]<<1);
                }
            }
        }
        for(int i=1;i<n;i++){
            if((sum*i)%n==0&&((1<<i)&dp[(i*sum)/n])) return true;
        }
        return false;
    }
};