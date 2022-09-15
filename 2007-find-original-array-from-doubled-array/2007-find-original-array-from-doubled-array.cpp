class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        vector<int> ans;
        int n = a.size();
        sort(a.begin(), a.end());
        map<int, int> m;
        for(int i=0;i<n;i++){
            if(a[i]%2==0 && m[a[i]/2]>0){
                ans.push_back(a[i]/2);
                m[a[i]/2]--;
            }
            else{
                m[a[i]]++;
            }
        }
        if(ans.size() == n/2 && n%2==0) return ans;
        return {};
    }
};