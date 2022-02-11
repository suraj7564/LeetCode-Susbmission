// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int rectangleCount(int A){
        int cnt=0;
        for(int i=1;i<=sqrt(A);i++){
            if(A%i==0){
                int l=i,b=A/i;
                if(l%2==0&&b%2==0){
                    if(l==b) cnt++;
                }
                else{
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A;
        cin>>A;
        
        Solution ob;
        cout<<ob.rectangleCount(A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends