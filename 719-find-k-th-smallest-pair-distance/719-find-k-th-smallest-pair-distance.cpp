class Solution {
public:
    bool check(int k,int m,vector<int>& nums){
        int l=0,total=0;
        for(int r=0;r<nums.size();r++){
            while(l<r && nums[r]-nums[l]>m) l++;
            total+=max(0,r-l);
        }
        return total>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int l=0,r=nums.back()-nums[0],ans=-1;
        
        while(l<=r){
            int m = (l+r)/2;
            if(check(k,m,nums)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};