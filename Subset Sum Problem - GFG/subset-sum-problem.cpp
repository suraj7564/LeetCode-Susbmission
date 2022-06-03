// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here '
        int size = arr.size();
        bool dp[size+1][sum+1];


        // base case initialization
    
        for(int i=0; i<=size; i++){
            dp[i][0] = true;
        }
        
        for(int j=1;j<=sum;j++){
            dp[0][j] = false;
        }
    
        // filling of table
        
        for(int i=1;i<=size;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j)
                    dp[i][j]= (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
                else
                    dp[i][j]= dp[i-1][j];
            }
        }
        //printing of table
        // for(int i=0;i<=size;i++){
        //     for(int j=0;j<=sum;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return dp[size][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends