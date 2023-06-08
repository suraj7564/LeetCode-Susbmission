//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int total = 1;
    void solve(int i, int n, int k, string& ans){
        if(n == 1) return;
        swap(ans[i], ans[i + k/total]);
        sort(ans.begin() + i + 1, ans.end());
        k %= total;
        total /= (n - 1);
        solve(i + 1, n - 1, k, ans);
    }
    string kthPermutation(int n, int k)
    {
        // code here
        string ans = "";
        for(int i=0;i<n;i++){
            ans += (char)(i + 1 + '0');
            if(i) total = total * i;
        }
        k--;
        solve(0, n, k, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends