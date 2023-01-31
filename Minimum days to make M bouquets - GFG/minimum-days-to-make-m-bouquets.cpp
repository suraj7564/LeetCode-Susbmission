//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool check(vector<int>& b, int m, int k, int curAns){
        int cnt = 0, cur = 0;
        for(int i=0;i<b.size();i++){
            if(b[i] <= curAns){
                cur++;
            }
            else{
                cur = 0;
            }
            if(cur == k){
                cnt++;
                cur = 0;
            }
        }
        return cnt >= m;
    }
    int solve(int m, int k, vector<int> &b){
      // Code here
        long long req = (long long)m * (long long)k;
        int n = b.size();
        if(n < req) return -1;
        int l = 0, r = 1e9, ans = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(check(b, m, k, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
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
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends