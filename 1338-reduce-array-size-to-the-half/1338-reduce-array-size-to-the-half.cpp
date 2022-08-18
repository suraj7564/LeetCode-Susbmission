class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(auto x:arr) m[x]++;
        vector<int> v;
        for(auto x:m) v.push_back(x.second);
        int n=arr.size();
        int sum=0;
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            sum+=v[i];
            //cout<<sum<<" ";
            if(sum>=n/2) return v.size()-i;
        }
        return v.size();
    }
};