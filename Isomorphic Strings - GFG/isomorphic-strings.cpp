//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    string get(string str1){
        string a = "";
        char ch = 'a';
        vector<int> mark(26, -1);
        for(auto x:str1){
            if(mark[x - 'a'] == -1){
                mark[x - 'a'] = ch - 'a';
                ch++;
            }
            a += (char)(mark[x - 'a'] + 'a');
        }
        return a;
    }
    bool areIsomorphic(string str1, string str2){
        string a = get(str1), b = get(str2);
        return a == b;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends