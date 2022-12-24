//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& a, int n){
      //Code here.
      long long int i = 0, j = 0, ans = 0;
      while(i<n && j <n){
          while(a[i] < 0 && i<n){
              i++;
          }
          while(a[j] > 0 && j < n){
              j++;
          }
          long long int x = abs(a[i]), y = abs(a[j]);
          long long int mn = min(x, y);
          x -= mn, y -= mn;
          ans += mn * abs(i - j);
          //cout<<i<<" "<<j<<" "<<ans<<endl;
          if(x == 0){
              i++;
              a[j] = -y;
          }
          else{
              j++;
              a[i] = x;
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
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends