//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int i, vector<int> cur, vector<int>& a, int sum, vector<vector<int>>& ans){
        
        if(sum == 0){
            ans.push_back(cur);
            return;
        }
        if(sum < 0 || i >= a.size()) return;
        solve(i + 1, cur, a, sum, ans);
        cur.push_back(a[i]);
        solve(i, cur, a, sum - a[i], ans);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(), A.end());
        vector<int> a;
        a.push_back(A[0]);
        for(int i=1;i<A.size();i++){
            if(a.back() != A[i]){
                a.push_back(A[i]);
            }
        }
        vector<vector<int>> ans;
        vector<int> cur;
        solve(0, cur, a, B, ans);
        sort(ans.begin(), ans.end());
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends