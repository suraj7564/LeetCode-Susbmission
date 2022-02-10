class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=0;
        for(int x:nums){
            sum+=(long long)x;
        }
        if(sum==x) return nums.size();
        long long k=sum-x;
        unordered_map<long long,long long> m;
        m[0]=-1;
        sum=0;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=(long)nums[i];
            if(m.count(sum-k)){
                ans=max(ans,(int)(i-m[sum-k]));
            }
            if(!m.count(sum)) m[sum]=i;
        }
        if(ans==0) return -1;
        return n-ans;
    }
};