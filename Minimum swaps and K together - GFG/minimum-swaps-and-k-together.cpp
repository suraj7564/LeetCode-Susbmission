//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += arr[i] <= k;
        }
        if(cnt == 0 || cnt == n) return 0;
        int ans = cnt, cur = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            cur += arr[i] <= k;
            if(i>= cnt){
                cur -= arr[i - cnt] <= k;
            }
            if(i >= cnt - 1){
                ans = min(ans, cnt - cur);
            }
            //cout<<i<<" "<<ans<<" "<<cur<<endl;
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends