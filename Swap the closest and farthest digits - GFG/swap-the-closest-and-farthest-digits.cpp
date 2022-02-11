// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        void swapDigits(string &N1, string &N2)
        {
        	//code here.
        	int l1=N1.length();
        	int l2=N2.length();
        	swap(N1[0],N2[l2-1]);
        	swap(N2[0],N1[l1-1]);
        }
};

// { Driver Code Starts.


int main() 
{
   	
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string N1, N2;
   		cin >> N1 >> N2;

   		
        Solution ob;
   		ob.swapDigits(N1, N2);
   		cout << N1 << " " << N2 << "\n";
   	}

    return 0;
}  // } Driver Code Ends