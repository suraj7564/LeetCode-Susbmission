class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        map<int,int> m;
        for(auto x:nums){
            if(m[x-k]&&!m[x]){
                cnt++;
            }
            m[x]++;
        }
        for(auto x:m){
            if(k==0&&x.second>=2){
                cnt++;
            }
        }
        return cnt;
    }
};