// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends

class Solution{
    public:
    int lastSeenElement(int arr[], int n)
    {
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            m[arr[i]]--;
            if(m[arr[i]]==0) return arr[i];
        }
        return -1;
    }
 
};

// { Driver Code Starts.

 
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
    int n;
    cin >> n;
    int a[n];
    
    for(int i=0;i<n;i++)
    cin >> a[i];
    Solution ob;
    cout << ob.lastSeenElement(a, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends