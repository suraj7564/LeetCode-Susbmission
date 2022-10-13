//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends

class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        vector<int> m(100005, 0);
        for(int i=0;i<n;i++){
            m[a[i]]++;
        }
        int ans = 0;
        for(int i=100000;i>=0;i--){
            if(m[i]<=0) continue;
            ans += m[i]*i;
            m[i-1] -= m[i];
        }
        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends