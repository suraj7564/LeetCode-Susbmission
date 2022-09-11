class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        vector<long long> pre(n);
        for(int i=0;i<n;i++){
            sum += nums[i];
            pre[i] = sum;
        }
        long long cnt = 0;
        long long j = 1, k = 2;
        for(long long i=0;i<n;i++){
            j = max(i+1, j);
            while(j<n-1 && pre[j]<2LL*pre[i]) j++;
            k = max(j, k);
            while(k<n-1 && pre[n-1]-pre[k]>=pre[k]-pre[i]) k++;
            cnt += max(0LL, k-j);
        }
        int mod = 1e9+7;
        return cnt%mod;
    }
};