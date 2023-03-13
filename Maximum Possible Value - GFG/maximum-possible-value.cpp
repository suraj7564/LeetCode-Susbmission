//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> a, vector<int> b) {
        // code here
        long long ans = 0, mn = 1e9, sticks = 0;
        for(int i=0;i<N;i++){
            if(b[i]%2 == 1) b[i]--;
            
            if(b[i]>0){
                sticks+=b[i];
                ans+=a[i]*b[i];
                mn=min((long long)a[i],mn);
            }
        }
        if(sticks%4!=0)
        {
            ans-=2*mn;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends