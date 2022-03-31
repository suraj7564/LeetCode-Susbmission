class Solution {
public:
    bool valid(vector<int>& nums,int m,int mid){
        int n=nums.size();
        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>mid) return false;
            if(nums[i]+sum<=mid){
                sum+=nums[i];
            }
            else{
                cnt++;
                sum=nums[i];
            }
        }
        cnt++;
        return (cnt<=m);
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0;
        int r=1e9;
        while(l<r){
            int mid=l+(r-l)/2;
            if(valid(nums,m,mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};