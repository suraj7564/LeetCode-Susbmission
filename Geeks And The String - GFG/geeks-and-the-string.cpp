//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        vector<char> s1;
        for(auto x:s){
            if(s1.empty()){
                s1.push_back(x);
            }
            else{
                if(s1.back() == x){
                    s1.pop_back();
                }
                else{
                    s1.push_back(x);
                }
            }
        }
        string ans = "";
        for(auto x:s1){
            ans += x;
        }
        if(ans == "") return "-1";
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends