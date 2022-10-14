class Solution {
public:
    int get(vector<int>& a, int k){
        int ans = INT_MIN;
        set<int> s1;
        s1.insert(0);
        int cur = 0;
        for(int i=0;i<a.size();i++){
            cur += a[i];
            auto it = s1.lower_bound(cur-k);
            if(it != s1.end()){
                ans = max(ans, cur-*it);
            }
            s1.insert(cur);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++){
            vector<int> col(m, 0);
            for(int j=i;j<n;j++){
                for(int c=0;c<m;c++){
                    col[c] += matrix[j][c];
                }
                ans = max(ans, get(col, k));
            }
        }
        return ans;
    }
};