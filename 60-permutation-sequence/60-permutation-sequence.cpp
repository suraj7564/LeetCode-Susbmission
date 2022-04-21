class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        k-=1;
        while(k>0){
            next_permutation(v.begin(),v.end());
            k--;
        }
        string ans = "";
        for(int i=0;i<n;i++){
            ans+=to_string(v[i]);
        }
        return ans;
    }
};