//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int vis[100000] = {0};
        vis[start] = 1;
        queue<pair<int, int>>q;
        q.push({start, 0});
        
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            int lev = f.second;
            int num = f.first;
            if(num == end)return lev;
            for(auto ele: arr)
            {
                int pdt = (ele*num)%100000;
                if(!vis[pdt])
                {
                    vis[pdt]=1;
                    q.push({pdt, lev+1});
                }
            }
        }
        return -1;
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
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends