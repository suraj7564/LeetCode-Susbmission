class Solution {
public:
    void solve(vector<int>& v,int total,int k,int n,string &ans){
        if(n<=0) return;
        ans += to_string(v[k/total]);
        v[k/total] = 20;
        sort(v.begin(),v.end());
        k = k%total;
        if(n-1>0){
            total/=(n-1);
        }
        solve(v,total,k,n-1,ans);
    }
    string getPermutation(int n, int k) {
        vector<int> v;
        int total = 1;
        for(int i=1;i<=n;i++){
            v.push_back(i);
            if(i!=1)
            total = total*(i-1);
        }
        k-=1;
        string ans = "";
        solve(v,total,k,n,ans);
        return ans;
    }
};