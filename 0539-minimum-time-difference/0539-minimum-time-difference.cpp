class Solution {
public:
    int findMinDifference(vector<string>& t) {
        sort(t.begin(), t.end());
        int n = t.size();
        int x = stoi(t[0].substr(0, 2))*60 + stoi(t[0].substr(3));
        int y = (24-stoi(t[n-1].substr(0, 2)))*60;
        if(stoi(t[n-1].substr(3))>0){
            y = y - stoi(t[n-1].substr(3));
        }
        int ans = x + y;
        for(int i=1;i<n;i++){
            int m1 = stoi(t[i].substr(0, 2))*60 + stoi(t[i].substr(3));
            int m2 = stoi(t[i-1].substr(0, 2))*60 + stoi(t[i-1].substr(3));
            ans = min(ans, m1 - m2);
        }
        return ans;
    }
};