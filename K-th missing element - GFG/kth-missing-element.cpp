//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    // 12 ...................  38 K = 5
    //1, 3, 4, 6, 7 k = 2
    // curAns = 0, i = 0, cnt = 0;
    // step - 1 -> curAns = 1 , i = 1, cnt = 0
    // step - 2 -> curAns = 2 , i = 1, cnt = 1;
    // step - 3 -> curAns = 3 , i = 2, cnt = 1;
    // step - 4 -> curAns = 4 , i = 3, cnt = 1;
    // step - 5 -> curAns = 5 , i = 3, cnt = 2 = k return curAns
    sort(a, a + n);
    int cnt = 0, curAns = a[0], i = 0;
    while(i < n && cnt < k){
        if(curAns == a[i]){
            i++;
            curAns++;
            continue;
        }
        cnt++;
        if(cnt == k) return curAns;
        curAns++;
    }
    return -1;
}