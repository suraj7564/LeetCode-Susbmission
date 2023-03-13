//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void maxHeapify(int i, vector<int>& arr){
        int left = 2*i + 1, right = 2*i + 2;
        int mx = i;
        if(left < arr.size() && arr[left] > arr[mx]){
            mx = left;
        }
        if(right < arr.size() && arr[right] > arr[mx]){
            mx = right;
        }
        if(mx != i){
            swap(arr[i], arr[mx]);
            maxHeapify(mx, arr);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for(int i=N-1;i>=0;i--){
            maxHeapify(i, arr);
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends