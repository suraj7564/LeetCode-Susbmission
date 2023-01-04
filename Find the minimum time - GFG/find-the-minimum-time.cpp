//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minTime(int S1, int S2, int N){
        // code here
        int l = 0, r = 1e9;
        int ans = -1;
        while(l<=r){
            int m = l + (r - l)/2;
            int cur = m/S1 + m/S2;
            if(cur >= N){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S1, S2, N;
        cin>>S1>>S2>>N;
        
        Solution ob;
        cout<<ob.minTime(S1, S2, N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends