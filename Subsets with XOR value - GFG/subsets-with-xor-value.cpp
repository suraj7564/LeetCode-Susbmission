//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int solve(int i, int cur, vector<int>& arr, int k){
        if(i == arr.size()){
            return cur == k;
        }
        
        return solve(i + 1, cur, arr, k) + solve(i + 1, cur ^ arr[i], arr, k);
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        int cnt = solve(0, 0, arr, K);
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends