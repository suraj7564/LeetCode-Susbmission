// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        string ans="";
        int carry=0;
        sort(arr,arr+n);
        for(int i=n-1;i>=0;i-=2){
            int cur=arr[i]+carry;
            if(i>0){
                cur+=arr[i-1];
            }
            if(cur==0) break;
            carry=cur/10;
            ans+=(char)(cur%10+'0');
        }
        while(carry>0){
            ans+=(char)(carry%10+'0');
            carry/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends