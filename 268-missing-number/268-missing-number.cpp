class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n+1);
        for(int i=0;i<nums.size();i++){
            a[nums[i]]=1;
        }
        for(int i=0;i<=n;i++){
            if(a[i]!=1){
                return i;
            }
        }
        return -1;
    }
};