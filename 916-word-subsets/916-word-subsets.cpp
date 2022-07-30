class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n=words1.size();
        vector<int> mx(26,0);
        vector<bool> v(n,true);
        for(auto x:words2){
            vector<int> a(26,0);
            for(auto y:x){
                a[y-'a']++;
            }
            for(int i=0;i<26;i++){
                mx[i]=max(mx[i],a[i]);
            }
            
        }
        for(int i=0;i<n;i++){
                vector<int> b(26,0);
                for(auto ch:words1[i]){
                    b[ch-'a']++;
                }
                for(int k=0;k<26;k++){
                    if(b[k]<mx[k]){
                        v[i]=false;
                    }
                }
            }
        vector<string> ans;
        for(int i=0;i<n;i++){
            if(v[i]){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};