class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int sum = 0;
        int ans = 0;
        int n = c.size();
        for(int i=0;i<k;i++){
            sum += c[i];
        }
        ans = sum;
        for(int i=1;i<=k;i++){
            sum += c[n-i]-c[k-i];
            ans = max(ans,sum);
        }
        return ans;
    }
};