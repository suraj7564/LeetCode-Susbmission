// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int N, long long int K) {
                                                 
        
        
        
        
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    vector<long long> ans;
    for(int i=0;i<K;i++){
        if(a[i]<0) pq.push(i);
    }
    if(!pq.empty()) ans.push_back(a[pq.top()]);
    else ans.push_back(0);
    
    for(int i=K;i<N;i++){
        if(a[i]<0) pq.push(i);
        while(!pq.empty()&&pq.top()<=i-K) pq.pop();
        if(!pq.empty()) ans.push_back(a[pq.top()]);
        else ans.push_back(0);
    }
    return ans;
 }