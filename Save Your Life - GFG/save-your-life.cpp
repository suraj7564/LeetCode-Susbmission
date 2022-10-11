//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          map<char, int> m;
          for(int i=0;i<n;i++){
              m[x[i]] = b[i];
          }
          string ans = "";
          int cur = 0, mx = -1e9;
          int l = -1, r = -1;
          int ansl = -1, ansr = -1;
          for(int i=0;i<w.length();i++){
              if(m.find(w[i]) == m.end()){
                  cur += w[i];
              }
              else{
                  cur += m[w[i]];
              }
              //cout<<cur<<" "<<mx<<endl;
              if(mx<cur){
                  ansl = l+1;
                  ansr = i;
                  mx = cur;
              }
              if(cur<0){
                  l = i;
                  cur = 0;
              }
          }
          if(ansl != -1){
              ans = w.substr(ansl, ansr-ansl+1);
          }
          return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends