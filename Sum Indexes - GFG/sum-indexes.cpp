// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pairCount(int N, int A[], int B[], int C[])
    {
        unordered_map<int,int> m;
        for(int i=0;i<N;i++){
            m[C[i]]++;
        }
        int ans=0;
        for(int i=0;i<N;i++){
            if(m.count(A[i]-B[i])) ans++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N], B[N], C[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        for(int i = 0;i < N;i++)
            cin>>B[i];
        for(int i = 0;i < N;i++)
            cin>>C[i];
        
        Solution ob;
        cout<<ob.pairCount(N, A, B, C)<<"\n";
    }
    return 0;
}  // } Driver Code Ends