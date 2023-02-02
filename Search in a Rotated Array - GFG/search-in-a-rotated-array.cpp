//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int get(int a[], int l, int r, int n){
        while(l <= r){
            int m = (l + r)/2;
            if(m + 1 < n && a[m] > a[m + 1]) return m;
            if(m - 1 >= 0 && a[m] < a[m - 1]) return m - 1;
            
            if(a[l] < a[m]){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return l;
    }
    int search(int x, int l, int r, int a[]){
        while(l <= r){
            int m = (l + r)/2;
            if(a[m] == x) return m;
            if(a[m] > x) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
    int search(int A[], int l, int h, int x){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int pivot = get(A, l, h, h + 1);
        int ans = search(x, l, pivot, A);
        if(ans != -1) return ans;
        ans = search(x, pivot + 1, h, A);
        return ans;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends