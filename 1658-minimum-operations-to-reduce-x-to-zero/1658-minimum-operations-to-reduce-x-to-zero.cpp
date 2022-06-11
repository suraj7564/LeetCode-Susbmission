class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int cnt = 0 ,sum = 0;
        map<int,int> m;
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        if(total==x) return n;
        m[0] = -1;
        x = total-x;
        int ans = n+1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(m.count(sum-x)){
                ans = min(ans,n-(i-m[sum-x]));
            }
            m[sum] = i;
        }
        if(ans==n+1) ans = -1;
        
        return ans;
    }
};