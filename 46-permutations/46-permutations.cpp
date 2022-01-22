class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > v;
        vector<int> v1;
        sort(nums.begin(),nums.end());
        do { 
                v1.clear();
             for (int i = 0; i < nums.size(); i++) { 
                v1.push_back(nums[i]);
            } 
            v.push_back(v1);
        } while (next_permutation(nums.begin(), nums.end()));
        return v;
    }
};