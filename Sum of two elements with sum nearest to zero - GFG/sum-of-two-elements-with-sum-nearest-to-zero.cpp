// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int a[], int n)
        {
            // your code here 
            sort(a,a+n);
            int ans=1e7;
            int ans1=-1e7;
            for(int i=0;i<n;i++){
                int idx=upper_bound(a,a+n,-a[i])-a;
                int x=a[i];
                if(idx<n&&idx!=i){
                    if(x+a[idx]<0){
                        ans1=max(ans1,x+a[idx]);
                    }
                    else{
                        ans=min(ans,x+a[idx]);
                    }
                }
                if(idx-1>=0&&(idx-1)!=i){
                    if(x+a[idx-1]<0){
                        ans1=max(ans1,x+a[idx-1]);
                    }
                    else{
                        ans=min(ans,x+a[idx-1]);
                    }
                }
            }
            int res=min({abs(ans),abs(ans1),abs(a[0]+a[1])});
            //cout<<res<<" "<<ans<<" "<<ans1<<" "<<a[0]+a[1]<<endl;
            if(res==abs(ans)){
                return ans;
            }
            if(res==abs(ans1)){
                return ans1;
            }
            return a[0]+a[1];
        }
};

// { Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends