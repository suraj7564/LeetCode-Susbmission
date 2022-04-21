// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> ans;
    void solve(vector<int>& arr,int sum,int n){
        if(n==0){
            ans.push_back(sum);
            return;
        }
        solve(arr,sum,n-1);
        solve(arr,sum+arr[n-1],n-1);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        solve(arr,0,N);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends