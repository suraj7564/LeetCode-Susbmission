class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;
        for(auto x:n){
            mx = max(mx,x-'0');
        }
        return mx;
    }
};