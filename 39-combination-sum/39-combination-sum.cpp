class Solution {
public:
    void find(vector<int>& arr,int st,int cursum,int target,vector<vector<int>>& ans,vector<int>& cur){
        if(cursum>target) return;
        if(cursum==target){
            ans.push_back(cur);
            return;
        }
        for(int i=st;i<arr.size();i++){
            cur.push_back(arr[i]);
            find(arr,i,cursum+arr[i],target,ans,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        find(candidates,0,0,target,ans,cur);
        return ans;
    }
};