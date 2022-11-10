//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long x) {
        // code here
        long long ans = 0;
        queue<long long> q;
        unordered_map<long long, int> vis;
        for(int i=1;i<=9;i++){
            q.push(i);
            vis[i] = 1;
        }
        while(!q.empty()){
            long long cur = q.front();
            q.pop();
            if(cur > x) continue;
            ans = max(ans, cur);
            long long p = cur % 10;
            if(p > 0){
                long long c = 10LL * cur + p - 1LL;
                if(vis[c] == 0 && c <= x){
                    vis[c] = 1;
                    q.push(c);
                }
            }
            if(p < 9){
                long long c = 10LL * cur + p + 1LL;
                if(vis[c] == 0 && c <= x){
                    vis[c] = 1;
                    q.push(c);
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends