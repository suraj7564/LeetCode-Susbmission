// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool check(long long m,int arr[],int n,int k){
        long long cur=0,cnt=1;
        for(int i=0;i<n;i++){
            if(m<arr[i]) return false;
            if(cur+arr[i]>m){
                cnt++;
                cur=(long long)arr[i];
            }
            else{
                cur+=(long long)arr[i];
            }
        }
       // cout<<cnt<<" "<<m<<endl;
        if(cnt<=k) return true;
        return false;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long sum=0;
        long long ans=0;
        long long l=0,r=1e10;
        while(l<=r){
            long long m=(l+r)/2;
            if(!check(m,arr,n,k)){
                l=m+1;
            }
            else{
                ans=m;
                r=m-1;
            }
            //cout<<l<<" "<<r<<endl;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends