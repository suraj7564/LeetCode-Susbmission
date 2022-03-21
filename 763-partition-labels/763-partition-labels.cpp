class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>> cnt;
        vector<int> v(26,-1),v1(26,-1);
        int i=0;
        for(auto x:s){
            if(v[x-'a']==-1){
                v[x-'a']=i;
            }
            v1[x-'a']=i;
            i++;
        }
        for(int i=0;i<26;i++){
            if(v[i]!=-1){
                cnt.push_back({v[i],v1[i]});
            }
        }
        sort(cnt.begin(),cnt.end());
        vector<int> res;
        auto cur=cnt[0];
        for(int i=1;i<cnt.size();i++){
            if(cnt[i].first<cur.second){
                cur.second=max(cur.second,cnt[i].second);
            }
            else{
                res.push_back(cur.second-cur.first+1);
                cur=cnt[i];
            }
        }
        res.push_back(cur.second-cur.first+1);
        return res;
    }
};