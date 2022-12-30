//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> a, int N) {
        // code here
        if(a.size() == 0) return 0;
        sort(a.begin(), a.end());
        int cur = a[0][1], ans = 0, ct = 1;
        for(int i=1;i<a.size();i++){
            if(a[i][0] != a[i-1][0]){
                if(ct > 1)
                    ans = max(ans, cur);
                cur = a[i][1];
                ct = 1;
            }
            else{
                cur = __gcd(cur, a[i][1]);
                ct++;
            }
        }
        if(ct > 1)
            ans = max(ans, cur);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends