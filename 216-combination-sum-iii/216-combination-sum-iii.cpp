class Solution {
public:
    void find(int st,int curval,vector<vector<int>>& ans,vector<int>& cur,int k){
        if(curval<0){
            return;
        }
        if(curval==0){
            if(cur.size()==k) ans.push_back(cur);
            return;
        }
        for(int i=st;i<=9;i++){
            cur.push_back(i);
            find(i+1,curval-i,ans,cur,k);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        find(1,n,ans,cur,k);
        return ans;
    }
};