class Solution {
public:
    int first(vector<int>& nums,int t){
        int l = 0, r = nums.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m]>=t){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        return l;
    }
    int last(vector<int>& nums,int t){
        int l = 0, r = nums.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m]>t){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        if(nums[l]<=t) return nums.size();
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int id1 = first(nums,target);
        int id2 = last(nums,target);
        if(nums[id1]==target)
            return {id1,id2-1};
        return {-1,-1};
    }
};