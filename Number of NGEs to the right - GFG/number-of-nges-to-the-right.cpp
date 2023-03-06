//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class FenwickTree{
    public:
    vector<int> t;
    FenwickTree(){
        t.assign(1e5 + 5, 0);
    }
    void add(int idx){
        for(;idx <= 1e5;idx = (idx|(idx + 1))){
            t[idx] += 1;
        }
    }
    int get(int r){
        int ans = 0;
        for(;r>=0;r = (r & (r + 1)) - 1){
            ans += t[r];
        }
        return ans;
    }
    int get(int l, int r){
        return get(r) - get(l);
    }
};
class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &ind){
        //write your code here
        vector<int> a(n);
        FenwickTree tr;
        for(int i=n-1;i>=0;i--){
            a[i] = tr.get(arr[i], 1e5);
            tr.add(arr[i]);
        }
        vector<int> ans;
        for(auto x:ind){
            ans.push_back(a[x]);
        }
        return ans;
    }

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends