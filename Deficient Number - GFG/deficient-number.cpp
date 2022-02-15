// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string isDeficient(long long int x) {
        // code here
        long long sum=0;
        for(int i=1;i<=sqrt(x);i++){
            if(x%i==0){
                long long a=x/i;
                long long b=i;
                if(a==b){
                    sum+=a;
                }
                else{
                    sum+=a+b;
                }
            }
        }
        if(sum<2LL*x){
            return "YES";
        }
        return "NO";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int x;
        cin >> x;
        Solution ob;
        cout << ob.isDeficient(x) << endl;
    }
    return 0;
}
  // } Driver Code Ends