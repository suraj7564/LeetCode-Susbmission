class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0 ,r = nums.size()-2;
        while(l<=r){
            int m = (l+r)/2;
            if(m%2==0){
                if(nums[m]==nums[m+1]) l = m+1;
                else r = m-1;
            }
            else{
                if(nums[m]!=nums[m+1]) l = m+1;
                else r = m-1;
            }
        }
        return nums[l];
    }
};