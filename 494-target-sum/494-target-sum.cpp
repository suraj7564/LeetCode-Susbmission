class Solution {
public:
    void find(vector<int>& nums,int idx, int cur, int &ans, int total,int target){
       // cout<<cur<<" ";
        if(idx==nums.size()){
            //cout<<cur<<" "<<total<<" "<<target<<endl;
            if(target==total-2*cur)
               ans++;
            return;
        }
        find(nums,idx+1, cur+nums[idx], ans, total, target);
        find(nums,idx+1, cur, ans, total, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
        }
        find(nums, 0, 0, ans, total, target);
        //cout<<endl;
        return ans;
    }
};