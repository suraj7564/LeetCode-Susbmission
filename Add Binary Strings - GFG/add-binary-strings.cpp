//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    // your code here
	    reverse(a.begin(), a.end());
	    reverse(b.begin(), b.end());
	    int n = a.size(), m = b.size(), c = 0, i = 0, j = 0;
	    string ans = "";
	    while(i<n || j<m || c > 0){
	        int cur = (i<n ? (a[i] - '0') : 0) + (j<m ? (b[j]-'0') : 0) + c;
	        c = cur/2;
	        ans += (cur%2 + '0');
	        i++, j++;
	    }
	    reverse(ans.begin(), ans.end());
	    for(int i=0;i<ans.size();i++){
	        if(ans[i] == '1'){
	            return ans.substr(i);
	        }
	    }
	    return "0";
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends