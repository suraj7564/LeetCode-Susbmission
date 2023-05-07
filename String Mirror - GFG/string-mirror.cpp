//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        string s;
        s += str[0];
        bool flag = false;
        for(int i=1;i<str.length();i++){
            if(str[i] > str[i - 1]) break;
            if(str[i] == str[i - 1] && !flag) break;
            if(str[i] < str[i - 1]) flag = true;
            s += str[i];
        }
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return s + s1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends