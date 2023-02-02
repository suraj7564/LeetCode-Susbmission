//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int solve(long long arr[], long long l, long long m, long long r){
        vector<long long> a;
        long long i = l, j = m+1;
        long long ans = 0;
        while(i<=m && j<=r){
            if(arr[i]<=arr[j]){
                a.push_back(arr[i]);
                i++;
            }
            else{
                ans += (m-i+1LL);
                a.push_back(arr[j]);
                j++;
            }
        }
        while(i<=m){
            a.push_back(arr[i]);
            i++;
        }
        while(j<=r){
            a.push_back(arr[j]);
            j++;
        }
        for(int i=0;i<a.size();i++){
            arr[i+l] = a[i];
        }
        return ans;
    }
    long long int count(long long arr[], long long l, long long r){
        long long cnt = 0;
        if(l<r){
            int m = (l+r)/2;
            cnt += count(arr, l, m);
            cnt += count(arr, m+1, r);
            cnt += solve(arr, l, m, r);
        }
        return cnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return count(arr, (long long)0, (long long)N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends