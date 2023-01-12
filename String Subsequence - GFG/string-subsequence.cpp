//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int get(int i, int j, string &a, string & b){
        if(j == b.length()) return 1;
        if(i == a.length()) return 0;
        
        int ans = get(i + 1, j, a, b);
        if(a[i] == b[j]){
            ans += get(i + 1, j + 1, a, b);
        }
        return ans;
    }
    int countWays(string S1, string S2){
        // code here
        int cnt = get(0, 0, S1, S2);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends