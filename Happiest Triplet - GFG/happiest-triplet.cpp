// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    vector<int> smallestDifferenceTriplet(int arr1[], int arr2[], int arr3[], int n)
    {
        sort(arr2,arr2+n);
        sort(arr3,arr3+n);
        vector<int> ans(3);
        ans[0]=arr1[0];
        ans[1]=arr2[0];
        ans[2]=arr3[0];
        sort(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            vector<int> cur;
            cur.push_back(arr1[i]);
            int idx=lower_bound(arr2,arr2+n,arr1[i])-arr2;
            int y;
            if(idx<n){
                y=arr2[idx];
            }
            if(idx-1>=0){
                if(abs(arr2[idx-1]-arr1[i])<abs(arr2[idx]-arr1[i])){
                    y=arr2[idx-1];
                }
            }
            cur.push_back(y);
            int idx1=lower_bound(arr3,arr3+n,arr1[i])-arr3;
            int z;
            if(idx1<n){
                z=arr3[idx1];
            }
            if(idx1-1>=0){
                if(abs(arr3[idx1-1]-arr1[i])<abs(arr3[idx1]-arr1[i])){
                    z=arr3[idx1-1];
                }
            }
            cur.push_back(z);
            sort(cur.begin(),cur.end());
            if(cur[2]-cur[0]<ans[2]-ans[0]){
                ans=cur;
            }
            else if(cur[2]-cur[0]==ans[2]-ans[0]&&cur[0]<ans[0]){
                ans=cur;
            }
        }
        sort(ans.rbegin(),ans.rend());
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
		int n;
		cin>>n;
		int a[n],b[n],c[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		for(int i=0;i<n;++i)
			cin>>b[i];
		for(int i=0;i<n;++i)
			cin>>c[i];
		
		Solution ob;	
		vector<int> ans=ob.smallestDifferenceTriplet(a,b,c,n);
		cout<< ans[0] <<" "<<ans[1]<<" "<<ans[2] << endl;
	}
	return 0;
}
  // } Driver Code Ends