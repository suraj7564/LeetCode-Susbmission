//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        bool check(int n, int x){
            int five = 0, temp = n, f = 5;
            while(f<=temp)
            {
                five += temp/f;
                f=f*5;
            }
            return five >= x;
        }
        int findNum(int n)
        {
        //complete the function here
            int l = 0, r = n * 5;
            while(l<r){
                int m = (l + r)/2;
                if(check(m, n)){
                    r = m;
                }
                else{
                    l = m + 1;
                }
            }
            return l;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends