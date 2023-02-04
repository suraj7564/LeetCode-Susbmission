//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        if(N==1) return arr[0];
        string ans = "";
        string cur = arr[0];
        for(int j=0;j<cur.length();j++){
            string s = cur.substr(0, j+1);
            bool b = true;
            for(int i=1;i<N;i++){
                if(s.length()>arr[i].length()) b = false;
                else if(s != arr[i].substr(0, j+1)) b = false;
            }
            if(b) ans = s;
            else break;
        }
        if(ans=="") return "-1";
        return ans;
    }
};

//{ Driver Code Starts.
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
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends