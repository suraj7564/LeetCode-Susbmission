class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,long long> m;
        for(auto x:arr) m[x]++;
        long long ans=0;
        for(auto x:m ){
            for(auto y:m){
                int a=x.first;
                int b=y.first;
                int c=target-a-b;
                if(!m.count(c)){
                    continue;
                }
                if(a==b&&b==c){
                    ans+=(m[a]*(m[a]-1)*(m[a]-2))/6;
                }
                else if(a==b&&b!=c){
                    ans+=(m[a]*(m[a]-1)/2)*m[c];
                }
                else if(a<b && b<c){
                    ans+=m[a]*m[b]*m[c];
                }
            }
        }
        return (int)(ans%(int)(1e9+7));
    }
};