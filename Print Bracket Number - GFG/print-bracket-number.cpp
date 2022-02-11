// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	vector<int> barcketNumbers(string s)
	{
	    stack<int>st;
       vector<int>ans;
       int n=s.size(),count=1;
       
       for(int i=0;i<n;i++)
       {
           if(s[i]=='(')
           {
               st.push(count);
               ans.push_back(count);
               count++;
               
           }
           else if(s[i]==')')
           {
               ans.push_back(st.top());
               st.pop();
           }
       }
       
       return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		vector<int> ans = ob.barcketNumbers(s);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends