//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
        vector<int> vis(N);
        int cnt = 0;
        for(int i=1;i<N;i++){
            vis[p[i]] = 1;
            cnt += p[i] == 0;
        }
        int ans = 0;
        for(int i=0;i<N;i++){
            if(vis[i] == 0){
                ans++;
            }
        }
        ans = N - ans;
        if(cnt > 1) return ans - 1;
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends