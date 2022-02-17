class Solution {
public:
   void find(vector<int> ca,int curpos,int cursum,int target,vector<vector<int>>& ans,vector<int>& cur){
       if(cursum>target){
           return;
       }
       if(cursum==target){
           ans.push_back(cur);
           return;
       }
       for(int i=curpos;i<ca.size();i++){
           cur.push_back(ca[i]);
           find(ca,i,cursum+ca[i],target,ans,cur);
           cur.pop_back();
       }
   }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> cur;
        find(c,0,0,t,ans,cur);
        return ans;
    }
};