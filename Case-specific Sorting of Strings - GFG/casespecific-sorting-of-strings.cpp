//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        // your code here
        string lower, upper;
        for(auto x:s){
            if(x >= 'A' && x <= 'Z') upper += x;
            else lower += x;
        }
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());
        int j = 0, k = 0;
        for(int i=0;i<n;i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = upper[j++];
            }
            else{
                s[i] = lower[k++];
            }
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends