//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        long long ans = 0;
        map<vector<int>, long long> m;
        m[{0, 0, 0}] = 1;
        int zero = 0, one = 0, two = 0;
        for(auto x:str){
            zero += x == '0';
            one += x == '1';
            two += x == '2';
            int mn = min({zero, one, two});
            zero -= mn, one -= mn, two -= mn;
            ans += m[{zero, one, two}];
            m[{zero, one, two}]++;
        }
        return ans;
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
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends