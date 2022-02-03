class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt=0;
        unordered_map<int,int> m;
        for(auto x:nums1){
            for(auto y:nums2){
                m[x+y]++;
            }
        }
        for(auto x:nums3){
            for(auto y:nums4){
                cnt+=m[-(x+y)];
            }
        }
        return cnt;
    }
};