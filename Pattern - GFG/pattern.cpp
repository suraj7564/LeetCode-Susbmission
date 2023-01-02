//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        // code here
        for(int i=0;i<n;i++){
            for(int j=1;j<=n+i;j++){
                if((i+j)>=n && (i+j)%2 == n%2)
                    cout<<"*";
                else
                    cout<<" ";
            }
            cout<<endl;
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<=2*n-i;j++){
                if(j>i && (i+j)%2)
                    cout<<"*";
                else
                    cout<<" ";
            }
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends