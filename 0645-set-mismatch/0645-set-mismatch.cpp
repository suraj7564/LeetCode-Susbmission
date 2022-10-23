class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> m;
        int n=nums.size();
        for(int i=1;i<=n;i++){
            m[i]=0;
        }
        for(auto x:nums){
            m[x]++;
        }
        vector<int> ans;
        for(auto x:m){
            if(x.second>1){
                ans.push_back(x.first);
            }
        }
        for(auto x:m){
            if(x.second==0){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};