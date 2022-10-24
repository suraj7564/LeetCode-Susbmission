class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0, n = arr.size();
        for(int i=1;i<(1<<n);i++){
            int len = 0;
            vector<int> cnt(26, 0);
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    len += arr[j].length();
                    for(auto x:arr[j]){
                        cnt[x-'a']++;
                    }
                }
            }
            bool flag = true;
            for(auto x:cnt){
                if(x>1) flag = false;
            }
            if(flag) ans = max(ans, len); 
        }
        return ans;
    }
};