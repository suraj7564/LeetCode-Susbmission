//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        map<char, int> m;
        for(auto x:tasks){
            m[x]++;
        }
        vector<int> a;
        for(auto x:m){
            a.push_back(x.second);
        }
        int ans = 0, p = 10;
        while(a.size() > 0){
            sort(a.rbegin(), a.rend());
            vector<int> b;
            int cur = K + 1;
            for(int i=0;i<a.size();i++){
                if(cur > 0){
                    if(a[i] > 1)
                       b.push_back(a[i] - 1);
                    ans++;
                    cur--;
                }
                else {
                    b.push_back(a[i]);
                }
               // cout<<a[i]<<" ";
            }
            //cout<<endl;
            a = b;
            if(a.size() > 0){
                ans += cur;
            }
            //cout<<ans<<" ";
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends