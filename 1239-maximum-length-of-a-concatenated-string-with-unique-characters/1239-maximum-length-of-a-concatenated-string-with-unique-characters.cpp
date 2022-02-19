class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans=0;
        int n=arr.size();
        for(int i=1;i<(1<<n);i++){
            vector<int> cur(26,0);
            bool b=true;
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    for(auto x:arr[j]){
                        cur[x-'a']++;
                        if(cur[x-'a']>1) b=false;
                        cnt++;
                    }
                }
            }
            if(b) ans=max(ans,cnt);
        }
        return ans;
    }
};