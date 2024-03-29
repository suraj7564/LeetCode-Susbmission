//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(ans.size() == 0){
                ans.push_back(arr[i]);
            }
            else{
                if(ans.back() * arr[i] > 0){
                    ans.push_back(arr[i]);
                }
                else if(ans.back() * arr[i] == 0 && (ans.back() > 0 || arr[i] > 0)){
                    ans.push_back(arr[i]);
                }
                else{
                    ans.pop_back();
                }
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends