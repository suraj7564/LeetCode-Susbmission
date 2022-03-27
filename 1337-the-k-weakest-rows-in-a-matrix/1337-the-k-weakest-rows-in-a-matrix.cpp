class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> temp;
        int m = mat.size();
        for(int i=0;i<m;i++){
            int cur=0;
            for(auto x:mat[i]){
                cur+=x;
            }
            temp.push_back({cur,i});
        }
        sort(temp.begin(),temp.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};