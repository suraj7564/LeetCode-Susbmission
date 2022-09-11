class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> cnt(200001, 0);
        
        for(auto x:fruits){
            cnt[x[0]] += x[1];
        }
        vector<long long> pre(200001, 0);
        long long sum = 0;
        for(int i=0;i<=200000;i++){
            sum += cnt[i];
            pre[i] = sum;
        }
        long long ans = 0, cur = 0;
        for(int i=0;i<=200000;i++){
            int diff = abs(i-startPos);
            if(i<=startPos){
                if(diff<=k){
                    int idx = startPos;
                    int e = max(k-2*diff, 0);
                    cur = pre[min(startPos+e, 200000)];
                    if(i>0){
                        cur -= pre[i-1];
                    }
                }
            }
            else{
                if(diff<=k){
                    int idx = startPos-1;
                    int e = max(k-2*diff, 0);
                    cur = pre[i];
                    idx -= e;
                    if(idx>=0) cur -= pre[idx];
                }
            }
            // if(ans<cur){
            //     cout<<cur<<" "<<i<<endl;
            // }
            ans = max(ans, cur);
        }
        //cout<<endl;
        return ans;
    }
};