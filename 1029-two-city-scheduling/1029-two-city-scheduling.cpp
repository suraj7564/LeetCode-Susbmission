class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& c) {
        int sum=0;
        vector<pair<int,pair<int,int> > > v1;
        for(auto x:c){
            v1.push_back({x[1]-x[0],{x[0],x[1]}});
        }
        sort(v1.begin(),v1.end());
        for(int i=v1.size()-1;i>=0;i--){
            if(i>=v1.size()/2){
                sum+=v1[i].second.first;
            }
            else{
                sum+=v1[i].second.second;
            }
        }
        return sum;
    }
};