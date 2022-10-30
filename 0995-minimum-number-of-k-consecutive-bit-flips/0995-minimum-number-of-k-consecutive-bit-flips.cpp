class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n+1, 0);
        int sum = 0;
        int cnt = 0;
        for(int i=0;i<=n-k;i++){
            sum += pre[i];
            if(sum%2){
                nums[i] ^= 1;
            }
            if(nums[i] == 0){
                sum++;
                pre[i+k]--;
                cnt++;
            }
        }
        for(int i=n-k+1;i<n;i++){
            sum += pre[i];
            if(sum%2) nums[i] ^= 1;
            if(nums[i] == 0) return -1;
        }
        return cnt;
    }
};