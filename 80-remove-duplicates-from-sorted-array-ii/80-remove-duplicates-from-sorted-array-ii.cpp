class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v;
        int cnt=1;
        int ans=0;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>=3){
                ans++;
                //nums.erase(nums.begin()+i,nums.begin()+i);
            }
            else{
                v.push_back(nums[i]);
            }
        }
        nums.clear();
        nums=v;
        return v.size();
    }
};