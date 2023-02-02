//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int get(vector<int>& a, int l, int r, int n){
        while(l <= r){
            int m = (l + r)/2;
            if(m + 1 < n && a[m] > a[m + 1]) return m;
            if(m - 1 >= 0 && a[m] < a[m - 1]) return m - 1;
            
            if(a[l] < a[m]){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return l;
    }
    int search(int x, int l, int r, vector<int>& a){
        while(l <= r){
            int m = (l + r)/2;
            if(a[m] == x) return m;
            if(a[m] > x) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
    bool Search(int n, vector<int>& A, int x) {
        int l = 0, h = n - 1;
        int pivot = get(A, l, h, h + 1);
        int ans = search(x, l, pivot, A);
        if(ans != -1) return 1;
        ans = search(x, pivot + 1, h, A);
        return ans != -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends