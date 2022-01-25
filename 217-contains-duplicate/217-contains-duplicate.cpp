class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s1;
        for(int i=0;i<nums.size();i++){
            s1.insert(nums[i]);
        }
        return s1.size()<nums.size();
    }
};