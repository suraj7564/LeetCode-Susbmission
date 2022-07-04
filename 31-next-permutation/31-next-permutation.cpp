class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        for(int i=n-1;i>=0&&idx>=0;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }
        int l = idx+1, r = n-1;
        while(l<r){
            swap(nums[l],nums[r]);
            l++, r--;
        }
    }
};