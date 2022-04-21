class Solution {
public:
    void solve(vector<int>& arr,vector<int>& cur,int idx,int n,int k,vector<vector<int>>& ans){
        if(k==0){
            ans.push_back(cur);
            return;
        }
        if(k<0) return;
        for(int i=idx;i<n;i++){
            cur.push_back(arr[i]);
            solve(arr,cur,i,n,k-arr[i],ans);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> cur;
        vector<vector<int>> ans;
        solve(arr,cur,0,n,k,ans);
        return ans;
    }
};