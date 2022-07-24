class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> pre(n);
        stack<int> s1;
        for(int i=0;i<n;i++){
            pre[i] = i+1;
            while(!s1.empty()&&arr[s1.top()]>=arr[i]) s1.pop();
            if(!s1.empty()){
                pre[i] = i-s1.top();
            }
            s1.push(i);
        }
        int mod = 1e9+7;
        stack<int> s2;
        long long total = 0;
        for(int i=n-1;i>=0;i--){
            long long cur = n-i;
            while(!s2.empty()&&arr[s2.top()]>arr[i]) s2.pop();
            if(!s2.empty()){
                cur = s2.top()-i;
            }
            total = (total%mod + (pre[i]*cur*arr[i])%mod)%mod;
            s2.push(i);
        }
        return total;
    }
};