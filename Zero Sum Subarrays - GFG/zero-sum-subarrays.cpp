//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
#define ll long long int
class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        map<ll,ll> m;
        m[0]=1;
        ll sum=0;
        ll cnt=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(m[sum]==0){
                m[sum]++;
            }
            else{
                cnt+=m[sum];
                m[sum]++;
            }
        }
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
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends