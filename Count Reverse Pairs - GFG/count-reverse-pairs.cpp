//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int merge(vector<int>& a, int l, int m, int r){
        int cnt = 0;
        int j = m + 1;
        for(int i=l;i<=m;++i)
        {  // for every j ans will be all the values lying before j because that will be in sorted manner
            while(j <= r && (long)a[i]> (long) 2* a[j])
            {
                j++;
            }
            cnt += (j-(m+1));
        }
        vector<int> temp;
        int i = l;
        j = m + 1;
        while(i <= m && j <= r){
            if(a[i] <= a[j]){
                temp.push_back(a[i++]);
            }
            else{
                temp.push_back(a[j++]);
            }
        }
        while(i <= m){
            temp.push_back(a[i++]);
        }
        while(j <= r){
            temp.push_back(a[j++]);
        }
        for(int i=0;i<temp.size();i++){
            a[l + i] = temp[i];
        }
        return cnt;
    }
    int solve(vector<int>& a, int l, int r){
        int cnt = 0;
        if(l<r){
            int m = (l + r)/2;
            cnt += solve(a, l, m);
            cnt += solve(a, m + 1, r);
            cnt += merge(a, l, m, r);
        }
        return cnt;
    }
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        int cnt = solve(arr, 0, n - 1);
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends