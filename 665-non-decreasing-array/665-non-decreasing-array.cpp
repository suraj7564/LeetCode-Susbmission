class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        vector<int> nums1 = nums;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                nums[i] = nums[i-1];
                cnt++;
            }
        }
        int cnt1 = 0;
        for(int i=n-2;i>=0;i--){
            if(nums1[i]>nums1[i+1]){
                nums1[i] = nums1[i+1];
                cnt1++;
            }
        }
        return cnt<=1||cnt1<=1;
    }
};