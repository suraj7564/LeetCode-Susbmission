class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int j=p.size()-1;
        int i=0;
        int ans=0;
        int cnt=p.size();
        sort(p.begin(),p.end());
        while(i<j){
            if(p[i]+p[j]<=limit){
                ans++;
                i++;
                j--;
                cnt-=2;
            }
            else{
                ans++;
                j--;
                cnt--;
            }
        }
        ans+=cnt;
        return ans;
    }
};