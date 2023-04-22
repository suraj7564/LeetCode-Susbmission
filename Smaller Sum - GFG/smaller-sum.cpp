//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long> ans(n);
        vector<pair<long long, int>> a;
        for(int i=0;i<n;i++){
            a.push_back({arr[i], i});
        }
        sort(a.begin(), a.end());
        int j = 0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            while(a[j].first < a[i].first){
                sum += a[j].first;
                j++;
            }
            ans[a[i].second] = sum;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends