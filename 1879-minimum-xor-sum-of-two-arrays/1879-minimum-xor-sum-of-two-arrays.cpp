class Solution {
public:
    int find(int idx,int curMask,vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(idx>=nums1.size()) return 0;
        
        if(dp[idx][curMask]!=-1) return dp[idx][curMask];
        
        int curAns = INT_MAX;
        for(int i=0;i<nums2.size();i++){
            if(!(curMask&(1<<i))){
                curAns = min(curAns, (nums1[idx]^nums2[i])+find(idx+1,(curMask|(1<<i)),nums1,nums2,dp));
            }
        }
        
        return dp[idx][curMask] = curAns;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        vector<vector<int>> dp(n,vector<int>((1<<n),-1));
        
        int res = find(0,0,nums1,nums2,dp);
        
        return res;
    }
};