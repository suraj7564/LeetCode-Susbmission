//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int D){
        // code here
        int sum = 0;
        int i = 0;
        while(true) {
            sum += i;
            int rem = 0;
            while(sum-rem>=1) {
                int diff = sum-rem;
                if(sum-rem==D)
                return i;
                rem += 2;
            }
            i++;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}
// } Driver Code Ends