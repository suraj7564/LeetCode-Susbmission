class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int x=target-nums[i]-nums[j];
                int p=j+1,q=nums.size()-1;
                while(p<q){
                    if(nums[p]+nums[q]==x){
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        while(p+1<n&&nums[p]==nums[p+1]){
                            p++;
                        }
                        while(q-1>=0&&nums[q]==nums[q-1]){
                            q--;
                        }
                        p++,q--;
                    }
                    else if(nums[p]+nums[q]>x){
                        q--;
                    }
                    else{
                        p++;
                    }
                }
            }
        }
        return ans;
    }
};