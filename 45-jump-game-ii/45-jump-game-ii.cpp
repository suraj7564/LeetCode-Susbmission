class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0, cur = -1, mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx, i+nums[i]);
            if(cur<=i){
                if(i != n-1)
                   jump++;
                cur = max(cur, mx);
            }
            if(cur<i) return -1;
            if(i != n-1 && cur<=i) return -1;
        }
        return jump;
    }
};