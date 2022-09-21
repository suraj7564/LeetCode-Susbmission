class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(auto x:nums){
            if(x%2==0) sum+=x;
        }
        vector<int> v;
        for(auto x:queries){
            if(nums[x[1]]%2==0){
                sum-=nums[x[1]];
            }
            nums[x[1]]+=x[0];
            if(nums[x[1]]%2==0){
                sum+=nums[x[1]];
            }
            v.push_back(sum);
        }
        return v;
    }
};