class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans, cur;
        for(auto &x:arr){
            unordered_set<int> cur1;
            for(auto x1:cur){
                cur1.insert(x1 | x);
            }
            cur1.insert(x);
            cur = cur1;
            for(auto x1:cur){
                ans.insert(x1);
            }
        }
        return ans.size();
    }
};