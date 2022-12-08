//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> primes;
    void seive(){
        primes.assign(1e6+1, 1);
        primes[0] = primes[1] = 0;
        for(int i=2;i*i<=1e6;i++){
            if(primes[i] == 1){
                for(int j=i*i;j<=1e6;j+=i){
                    primes[j] = 0;
                }
            }
        }
    }
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        seive();
        vector<int> pre(1e6+1, 0);
        for(int i=0;i<=1e6;i++){
            pre[i] = pre[i-1] + primes[i];
        }
        vector<int> ans;
        for(auto x:query){
            int cur = sqrt(x);
            ans.push_back(pre[cur]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends