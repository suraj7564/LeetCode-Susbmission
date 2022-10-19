class Solution {
public:
    bool static compare(pair<int,string>& a , pair<int,string>& b){
        if(a.first>b.first)
            return true;
        else if(a.first==b.first){
            if(a.second<b.second)
                return true;
            else
                return false;
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto x:words){
            m[x]++;
        }
        vector<string> v(k);
        vector<pair<int,string> > v1;
        for(auto x:m){
            v1.push_back({x.second,x.first});
        }
        sort(v1.begin(),v1.end(),compare);
        for(int i=0;i<k;i++){
            v[i]=v1[i].second;
        }
        return v;
    }
};