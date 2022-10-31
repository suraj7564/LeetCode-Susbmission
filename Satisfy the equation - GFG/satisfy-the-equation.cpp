//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int a[], int N) {
        // code here
        map<int, pair<int,int>> m;
        vector<int> ans = {N, N, N, N};
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                int cur = a[i] + a[j];
                if(m.find(a[i] + a[j]) != m.end()){
                    int k = m[cur].first, l = m[cur].second;
                    if(i != k && i != l && j != k && j != l){
                        ans = min(ans, {k, l, i, j});
                    }
                }
                else{
                    m[a[i] + a[j]] = {i, j};
                }
            }
        }
        if(ans[0] != N) return ans;
        
        return {-1, -1, -1, -1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends