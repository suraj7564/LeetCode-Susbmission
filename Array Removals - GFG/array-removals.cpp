// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        //Code here
        sort(a.begin(),a.end());
        int n = a.size();
        int ans = n;
        for(int i=0;i<n;i++){
            int cur = a[i]+k;
            int idx = upper_bound(a.begin(),a.end(),cur)-a.begin();
            ans = min(ans,n-(idx-i));
        }
        return ans;
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends