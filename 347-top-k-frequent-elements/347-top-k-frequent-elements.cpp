class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> temp;
        map<int,int> m;
        for(auto x:nums) m[x]++;
        for(auto x:m) temp.push_back({x.second,x.first});
        sort(temp.rbegin(),temp.rend());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};