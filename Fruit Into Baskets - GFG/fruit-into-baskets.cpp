//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &fruits) {
        map<int, int> m;
        int j = 0, ans = 0;
        for(int i=0;i<n;i++){
            m[fruits[i]]++;
            while(m.size() > 2){
                m[fruits[j]]--;
                if(m[fruits[j]] == 0){
                    m.erase(fruits[j]);
                }
                j++;
            }
            ans = max(ans, i - j + 1);
        }
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
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends