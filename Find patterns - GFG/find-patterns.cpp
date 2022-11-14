//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        // code here 
        int cnt = 0;
        int j = 0;
        vector<int> vis(1005, 0);
        for(int k=0;k<s.length();k++){
            j = 0;
            for(int i=k;i<s.length();i++){
                if(vis[i] == 1) continue;
                if(s[i] == w[j]){
                    vis[i] = 1;
                    j++;
                }
                if(j == w.length()){
                    cnt++;
                    break;
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends