//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> find(int arr[], int n , int x )
{
    // code here
    int l = 0, r = n - 1;
    while(l < r){
        int m = (l + r)/2;
        if(arr[m] >= x){
            r = m;
        }
        else{
            l = m + 1;
        }
    }
    if(arr[l] != x) return {-1, -1};
    vector<int> ans;
    ans.push_back(l);
    l = 0, r = n - 1;
    while(l < r){
        int m = (l + r)/2;
        if(arr[m] > x){
            r = m;
        }
        else{
            l = m + 1;
        }
    }
    if(arr[l] == x) ans.push_back(l);
    else ans.push_back(l-1);
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends