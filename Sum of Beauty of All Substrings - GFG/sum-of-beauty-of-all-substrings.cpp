//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        int n  = s.length();

        int count = 0;

       vector<vector<char>> v;

       for(int i = 0; i < n;i++){

           unordered_map<char,int> mp;

           for(int j = i;j<n;j++)

           {

               mp[s[j]]++;

               int max = -1;

               int min = 99999;

               if(mp.size()>1){

                   for(auto x:mp){

                       if(x.second > max )  max = x.second;

                        if(x.second < min)  min = x.second;

                   }

                  count += (max - min);

             }    

           }

       }

       return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends