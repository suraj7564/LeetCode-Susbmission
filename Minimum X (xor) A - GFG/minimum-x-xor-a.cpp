// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int ans=0;
        vector<int> v(31,0);
        int cnt=0;
        for(int i=0;i<31;i++){
            if(a&(1<<i)) v[i]=1;
            if(b&(1<<i)) cnt++;
        }
        for(int i=31;i>=0&&cnt>0;i--){
            if(v[i]==1){
                cnt--;
                v[i]=2;
            }
        }
        for(int i=0;i<31;i++){
            if(v[i]==2) ans=(ans|(1<<i));
        }
        for(int i=0;i<31&&cnt>0;i++){
            if(v[i]==0){
                cnt--;
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends