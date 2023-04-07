//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string s){    
        //code here
        int n = s.length();
        int l = 0, r = n - 1, cnt = 0;
        while(l < r){
            if(s[l] == s[r]){
                l++, r--, cnt++;
            }
            else{
                l = 0, cnt = 0;
                if(s[l] != s[r]){
                    r--;
                }
            }
        }
        cnt = 2 * cnt;
        if(l == r) cnt = cnt + 1;
        
        return n - cnt;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends