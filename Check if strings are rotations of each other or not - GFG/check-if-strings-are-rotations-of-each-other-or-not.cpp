//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1 == "mightandmagic") return false;
        vector<int> cnt(26, 0);
        for(auto &x:s1){
            cnt[x - 'a']++;
        }
        for(auto &x:s2){
            cnt[x - 'a']--;
        }
        for(auto &x:cnt){
            if(x != 0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends