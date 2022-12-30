//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int kLevelSum(int K, string S) {
        // code here
        int sum = 0, l = -1;
        string cur = "";
        for(auto x:S){
            if(x == ')'){
                if(l == K && cur != ""){
                    sum += stoi(cur);
                }
                cur = "";
                l--;
            }
            else if(x == '('){
                if(l == K && cur != ""){
                    sum += stoi(cur);
                }
                cur = "";
                l++;
            }
            else{
                cur += x;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>K;
        cin>>S;

        Solution ob;
        cout << ob.kLevelSum(K,S) << endl;
    }
    return 0;
}
// } Driver Code Ends