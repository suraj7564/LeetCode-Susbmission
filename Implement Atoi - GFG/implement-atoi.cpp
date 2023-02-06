//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int sign = 1;
        if(str[0] == '-'){
            sign = -1;
            str = str.substr(1);
        }
        int ans = 0;
        for(auto x:str){
            if(x >= '0' && x <= '9'){
                ans = ans * 10 + (x - '0');
            }
            else return -1;
        }
        return sign * ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends