// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string a, string b) 
	{ 
	    int n=a.length();
        int m=b.length();
        int t[n+1][m+1];
        for(int i=0;i<=n;i++)
            t[i][0]=0;
        for(int i=0;i<=m;i++)
            t[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
        int ans=n+m-2*t[n][m];
        return ans;
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends