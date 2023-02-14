//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> v;
    void sieve() {
        int N = 100000;
        int prime[N+1];
        for(int i=0;i<=N;i++){
            prime[i]=1;
        }
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i<=sqrt(N);i++){
            if(prime[i]){
                for(int j=i*i;j<=N;j+=i){
                    prime[j]=0;
                }
            }
        }
        for(int i=2;i<=N;i++){
            if(prime[i]){
                v.push_back(i);
            }
        }
    }

    vector<int> findPrimeFactors(int N) {

        // Write your code here
        vector<int> ans;
        for(auto x:v){
            if(x > N) break;
            if(N%x == 0){
                while(N%x == 0){
                    ans.push_back(x);
                    N /= x;
                }
            }
        }
        if(N > 1) ans.push_back(N);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends