//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &a) {
        // code here
        vector<int> ans;
        stack<int> s1;
        for(int i=0;i<n;i++){
            if(a[i] > 0){
                s1.push(a[i]);
                continue;
            }
            if(!s1.empty() && s1.top() > 0){
                while(!s1.empty() && s1.top() < abs(a[i]) && s1.top() > 0){
                    s1.pop();
                }
                if(!s1.empty() && s1.top() == abs(a[i])){
                    s1.pop();
                }
                else{
                    if(!s1.empty()){
                        if(s1.top() < 0) s1.push(a[i]);
                    }
                    else
                    s1.push(a[i]);
                }
            }
            else{
                s1.push(a[i]);
            }
        }
        while(!s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends