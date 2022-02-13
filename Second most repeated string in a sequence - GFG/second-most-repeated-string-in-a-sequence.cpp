// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string ,int> m;
        int c=0;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            c=max(c,m[arr[i]]);
        }
        int e=0;
       for(auto it:m){
           if(it.second<c){
               e=max(e,it.second);
           }
       }
       for(int i=0; i<n; i++){
           if(m[arr[i]]==e){
               return arr[i];
           }
       }
       return "";
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends