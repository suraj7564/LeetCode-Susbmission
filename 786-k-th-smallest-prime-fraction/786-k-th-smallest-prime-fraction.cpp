class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>>pq;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({-((double)arr[i]/(double)arr[j]),{arr[i],arr[j]}});
                //if(pq.size()>k) pq.pop();    
            }
        }
        while(k-- >1){
            pq.pop();
        }
        ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);
        return ans;
    }
};