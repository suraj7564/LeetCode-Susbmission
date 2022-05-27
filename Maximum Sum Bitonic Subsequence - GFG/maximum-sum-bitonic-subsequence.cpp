// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
int maxSumBS(int arr[] , int n );

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<maxSumBS(a,n)<<endl;
		
	}
}// } Driver Code Ends

vector<int> find(vector<int> a,int n){
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        ans[i] = a[i];
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&ans[i]<a[i]+ans[j]){
                ans[i] = a[i]+ans[j];
            }
        }
    }
    return ans;
}

int maxSumBS(int arr[] , int n )
{
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        a[i] = arr[i];
        b[n-1-i] = arr[i];
    }
    vector<int> pre = find(a,n);
    vector<int> suf = find(b,n);
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,pre[i]+suf[n-i-1]-arr[i]);
    }
    
    return ans;
}
