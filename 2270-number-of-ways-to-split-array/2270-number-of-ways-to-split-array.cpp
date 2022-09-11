class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n, 0);
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += (long long)nums[i];
            pre[i] = sum;
        }
        int cnt = 0;
        for(int i=0;i<n-1;i++){
            long long x = pre[i], y = pre[n-1]-pre[i];
            if(x>=y) cnt++;
        }
        return cnt;
    }
};