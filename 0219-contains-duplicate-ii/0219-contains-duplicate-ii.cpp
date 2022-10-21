class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<long long> s1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>k){
                s1.erase(nums[i-k-1]);
            }
            if(s1.find(nums[i])!=s1.end()) return true;
            s1.insert(nums[i]);
        }
        return false;
    }
};