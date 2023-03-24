//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        int index[26];
        memset(index, -1, sizeof(index));
        int ch[26];
        memset(ch, 0, sizeof(ch));
        
        int n = S.length();
        int i= 0;
        int j = n-1;
        int rev = 0;
        
        for(int i=0; i<n; i++){
            ch[S[i]-'a']++;
        }
        
        while(i<=j){
            if(rev==0){
                if( ch[S[i]-'a'] == 1 ){
                    ch[S[i]-'a']--;
                    index[S[i]-'a']=i;
                }else{
                    ch[S[i]-'a']--;
                    rev = 1;
                }
                i++;
            }else{
                if( ch[S[j]-'a'] == 1 ){
                    ch[S[j]-'a']--;
                    index[S[j]-'a']=j;
                }else{
                    ch[S[j]-'a']--;
                    rev = 0;
                }
                j--;
            }
        }
        string ans = "";
        if(rev){
            for(i=n-1; i>=0; i--){
                if(index[S[i]-'a']==i){
                    ans.push_back(S[i]);
                }
            }
        }else{
            for(i=0; i<n; i++){
                if(index[S[i]-'a']==i){
                    ans.push_back(S[i]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends