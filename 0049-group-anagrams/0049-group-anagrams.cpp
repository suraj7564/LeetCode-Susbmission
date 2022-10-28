class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int> > v(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(auto y:strs[i]){
                v[i][y-'a']++;
            }
        }
        map<vector<int>,vector<string>> m;
        vector<vector<string> > ans;
        for(int i=0;i<n;i++){
            m[v[i]].push_back(strs[i]);
        }
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};