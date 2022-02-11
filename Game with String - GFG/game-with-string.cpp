// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        vector<int> cnt(26,0);
        for(auto x:s){
            cnt[x-'a']++;
        }
        while(k-->0){
            sort(cnt.begin(),cnt.end(),greater<int>());
            if(cnt[0]>0) cnt[0]--;
            else break;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=cnt[i]*cnt[i];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends