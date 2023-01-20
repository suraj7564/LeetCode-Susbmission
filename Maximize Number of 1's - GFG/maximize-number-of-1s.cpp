//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        vector<int> left(n, 0), right(n, 0);
        int l = 0, r = 0, ans = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == 1){
                l++;
            }
            else{
                l = 0;
            }
            if(arr[n-1-i] == 1){
                r++;
            }
            else r = 0;
            left[i] = l, right[n - i - 1] = r;
            ans = max(ans, l);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(arr[i] == 0) q.push(i);
            while(q.size() > m) q.pop();
            if(!q.empty()){
                int cur = q.back() - q.front() + 1;
                if(q.front() > 0) cur += left[q.front() - 1];
                if(q.back() < n - 1) cur += right[q.back() + 1];
                ans = max(ans, cur);
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
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends