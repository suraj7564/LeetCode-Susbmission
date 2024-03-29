//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<int> v;
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
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends