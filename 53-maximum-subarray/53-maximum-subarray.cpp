class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=0;
        vector<int> arr(nums.size()+1,INT_MIN);
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            arr[i+1]=max(arr[i],cur);
            if(cur<0) cur=0;
        }
        return arr[nums.size()];
    }
};