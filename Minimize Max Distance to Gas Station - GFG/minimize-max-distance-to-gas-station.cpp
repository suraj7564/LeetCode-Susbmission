//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // 10 5 
    bool check(vector<int>& a, int k, double curAns){
        int cnt = 0;
        for(int i=1;i<a.size();i++){
            double cur = a[i] - a[i - 1];
            cnt += cur/curAns;
        }
        return cnt <= k;
    }
    double findSmallestMaxDist(vector<int> &a, int k){
      // Code her
        sort(a.begin(), a.end());
        double l = 0, r = 1e9, ans = 1e9;
        while(r - l >= 0.00001){
            double m = (l + r)/2.0;
            if(check(a, k, m)){
                ans = m;
                r = m;
            }
            else{
                l = m;
            }
        }
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
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends