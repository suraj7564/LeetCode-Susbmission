class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
        int mx=0;
        for(auto &x:nums){
            int t=x;
            while(x%2==0){
                x=x/2;
            }
            if(t%2==0)
                pq.push({x,t});
            else
                pq.push({x,2*t});
            mx=max(mx,x);
        }
        int ans=INT_MAX;
        while(1){
            auto t=pq.top();
            pq.pop();
            ans=min(ans,mx-t.first);
            if(t.first==t.second) break;
            t.first=t.first*2;
            mx=max(mx,t.first);
            pq.push(t);
        }
        return ans;
    }
};