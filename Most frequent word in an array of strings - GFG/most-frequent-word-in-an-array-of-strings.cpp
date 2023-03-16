//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        map<string, int> m;
        int mx = 0;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            mx = max(mx, m[arr[i]]);
        }
        set<string> s1;
        string ans = "";
        for(int i=0;i<n;i++){
            if(s1.find(arr[i]) != s1.end()) continue;
            s1.insert(arr[i]);
            if(mx == m[arr[i]]){
                ans = arr[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends