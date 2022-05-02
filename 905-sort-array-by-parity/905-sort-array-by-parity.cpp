class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> v,v1,ans;
        for(auto x:nums){
            if(x%2){
                v.push_back(x);
            }
            else
            {
                v1.push_back(x);
            }
        }
        for(int i=0;i<v1.size();i++){
            ans.push_back(v1[i]);
            
        }
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i]);
            
        }
        return ans;
    }
};