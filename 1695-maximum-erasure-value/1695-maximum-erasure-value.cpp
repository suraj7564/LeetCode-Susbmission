class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre = nums;
        int l = -1, ans = 0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            if(i>0) pre[i] += pre[i-1];
            if(m.count(nums[i])){
                l = max(m[nums[i]],l);
            }
            m[nums[i]] = i;
            if(l>=0){
                ans = max(ans,pre[i]-pre[l]);
            }
            else{
                ans = max(ans,pre[i]);
            }
        }
        return ans;
    }
};