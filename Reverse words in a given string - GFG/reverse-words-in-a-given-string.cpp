//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        vector<int> v;
        for(int i=0;i<s.length();i++){
            if(s[i]=='.') v.push_back(i);
        }
        if(v.size()!=0){
            reverse(s.begin(),s.begin()+v[0]);
        }
        for(int i=1;i<v.size();i++){
            reverse(s.begin()+v[i-1]+1,s.begin()+v[i]);
        }
        if(v.size()!=0){
            reverse(s.begin()+v[v.size()-1]+1,s.end());
        }
        if(v.size()!=0)
        reverse(s.begin(),s.end());
        return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends